<?php
include "Encryption.php";
if(!$_POST["Fil"])
{
    die("Go away");
}
$File = Decrypt($_POST["Fil"]);
$File = "Files/" . $File;
$down = file_get_contents($File);
die($down);

?>