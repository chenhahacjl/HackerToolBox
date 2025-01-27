<?php

//////////////////////////////////////////////////////////////////////////////////////////////
// The following lines should be generated by VMProtect License Manager
$exported_algorithm = "";
$exported_bits = 0;
$exported_private = "";
$exported_modulus = "";
$exported_product_code = "";
//////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////
// Fill the following array with data you want to be stored in serial number
$params = array(
	user_name => "John Doe", // UTF-8!
	email => "john@doe.com",
	hwid => "vHGMdMRvGCPjWcCQ", // Exactly as returned by VMProtectGetCurrentHWID
	expire_date => array(year => 2009, month => 10, day => 1),
	maxbuild_date => array(year => 2009, month => 10, day => 1),
	time_limit => 10,
	user_data => base64_decode("CGCvRvMWcPHGdMjQ"), // string of bytes
	);

// This function will be called after successfull generation of serial number
// You may print it here, send it by e-mail to customer or payment processing service
// You may send a copy to yourself
// $serial contains a single-line number, feel free to wrap it to several lines
function OnSerialGenerated($serial)
{
	$serial = wordwrap($serial, 75, "\n", true);
	echo $serial;
}


// This function will be called if something goes wrong. You will get a vendor-readable
// error description in details. It is a good place to send $details and $params to yourself
// by e-mail and send "Key will be delivered later" message to the customer
// Do not call die() here, it will be called after leaving the function
function OnSerialGenerationFailed($details)
{
	echo "You will receive serial number in the next 24 hours"; // message to the customer
//	mail("support@vendor.com", "Houston, we have a problem", $details); // message to vendor
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
// DO NOT TOUCH THE REST !!!

function base10_encode($str)
{
	$result = '0';
	for ($i = 0; $i < strlen($str); $i++)
	{
		$result = bcmul($result, 256);
		$result = bcadd($result, ord($str[$i]));
	}
	return $result;
}

function base10_decode($str)
{
	$result = '';
	while (bccomp($str, 0) > 0)
	{
		$result = chr((int)(bcmod($str, 256))).$result;
		$str = bcdiv($str, 256);
	}
	return $result;
}

function powmod($base, $exponent, $modulus)
{
	if( function_exists('gmp_powm')) // fast
		return gmp_strval(gmp_powm($base, $exponent, $modulus));
	if( function_exists('bi_powmod')) // not tested
		return bi_sto_str(bi_powmod($base, $exponent, $modulus));
	if( function_exists('bcpowmod')) // slow
		return bcpowmod($base, $exponent, $modulus);
        
	// emulation, slow
	$square = bcmod($base, $modulus);
	$result = 1;
	while (bccomp($exponent, 0) > 0) 
	{
		if (bcmod($exponent, 2)) 
			$result = bcmod(bcmul($result, $square), $modulus);
		$square = bcmod(bcmul($square, $square), $modulus);
		$exponent = bcdiv($exponent, 2);
	}
	return $result;
}

function my_die($error)
{
	OnSerialGenerationFailed($error);
	die();
}

function pack_serial($params)
{
	$serial = array();
	// 1. version
	$serial[] = 1;
	$serial[] = 1;
	// 2. user name
	if (array_key_exists("user_name", $params))
	{
		$user_name = $params["user_name"];
		if (strlen($user_name) > 255) my_die("User name is too long");
		$serial[] = 2;
		$len = strlen($user_name);
		$serial[] = $len;
		for ($i = 0; $i < $len; $i++) $serial[] = ord($user_name[$i]);
	}
	// 3. e-mail
	if (array_key_exists("email", $params))
	{
		$email = $params["email"];
		if (strlen($email) > 255) my_die("E-Mail is too long");
		$serial[] = 3;
		$len = strlen($email);
		$serial[] = $len;
		for ($i = 0; $i < $len; $i++) $serial[] = ord($email[$i]);
	}
	// 4. hardwareid
	if (array_key_exists("hwid", $params))
	{
		$hwid = $params["hwid"];
		$hwid = base64_decode($hwid);
		$len = strlen($hwid);
		if ($len == 0) my_die("HWID is empty");
		if ($len % 4 != 0) my_die("Invalid HWID (not multiple of 4): ".$len);
		$serial[] = 4;
		$serial[] = $len;
		for ($i = 0; $i < $len; $i++) $serial[] = ord($hwid[$i]);
	}
	// 5. date of expiration
	if (array_key_exists("expire_date", $params))
	{
		$dt_exp = $params["expire_date"];
		$y = $dt_exp["year"]; $m = $dt_exp["month"]; $d = $dt_exp["day"];
		if (!checkdate($m, $d, $y)) return my_die("Date of expiration is invalid: y=".$y." m=".$m." d=".$d);
		$serial[] = 5;
		$serial[] = $d;
		$serial[] = $m;
		$serial[] = $y % 256;
		$serial[] = $y / 256;
	}
	// 6. running time limit
	if (array_key_exists("time_limit", $params))
	{
		$limit = $params["time_limit"];
		if ($limit < 0 || $limit > 255) return my_die("Running time limit is incorrect: ".$limit);
		$serial[] = 6;
		$serial[] = $limit;
	}
	// 7. product code
	if (array_key_exists("product_code", $params))
	{
		$pc = $params["product_code"];
		$pc = base64_decode($pc);
		if (strlen($pc) != 8) return my_die("Product code has invalid size: ".strlen($pc));
		$serial[] = 7;
		for ($i = 0; $i < 8; $i++) $serial[] = ord($pc[$i]);
	}
	// 8. user data
	if (array_key_exists("user_data", $params))
	{
		$data = $params["user_data"];
		$len = strlen($data);
		if ($len > 255) return my_die("User data is too long: ".$len);
		$serial[] = 8;
		$serial[] = $len;
		for ($i = 0; $i < $len; $i++) $serial[] = ord($data[$i]);
	}
	// 9. max build date
	if (array_key_exists("maxbuild_date", $params))
	{
		$dt_exp = $params["maxbuild_date"];
		$y = $dt_exp["year"]; $m = $dt_exp["month"]; $d = $dt_exp["day"];
		if (!checkdate($m, $d, $y)) return my_die("Date of max build is invalid: y=".$y." m=".$m." d=".$d);
		$serial[] = 9;
		$serial[] = $d;
		$serial[] = $m;
		$serial[] = $y % 256;
		$serial[] = $y / 256;
	}

	return $serial;
}

if ($exported_algorithm != "RSA") my_die("Unsupported key generation algorithm: ".$exported_algorithm);

$params["product_code"] = $exported_product_code; // product code should be added always
$serial = pack_serial($params);
$serial_bin = "";
foreach ($serial as $b) $serial_bin = $serial_bin.pack("C", $b); // convert to binary
$hash = sha1($serial_bin);
$hash = pack("H*", $hash); 
$hash = sha1($serial_bin, true);
$serial_bin .= chr(255); // CRC chunk
for ($i = 3; $i >= 0; $i--) $serial_bin .= $hash[$i]; // add CRC in reverse order (little endian)
$padding_front = array(0, 2);
$size = rand(8, 16);
for ($i = 0; $i < $size; $i++) $padding_front[] = rand(1, 255);
$padding_front[] = 0;
$content_size = strlen($serial_bin) + count($padding_front);
$rest = $exported_bits / 8 - $content_size;
if ($rest < 0) my_die("content is too big to fit in key: ".$content_size.", maximal allowed is: ".($exported_bits / 8));
$padding_back = array();
for ($i = 0; $i < $rest; $i++) $padding_back[] = rand(0, 255);
$padding_front_bin = "";
foreach ($padding_front as $b) $padding_front_bin = $padding_front_bin.pack("C", $b);
$padding_back_bin = "";
foreach ($padding_back as $b) $padding_back_bin = $padding_back_bin.pack("C", $b);
$serial_final = $padding_front_bin.$serial_bin.$padding_back_bin;

// RSA
$n = base10_encode(base64_decode($exported_modulus));
$d = base10_encode(base64_decode($exported_private));
$serial_final = base10_encode($serial_final);
$res = powmod($serial_final, $d, $n);
$res = base64_encode(base10_decode($res));
OnSerialGenerated($res);

?>
