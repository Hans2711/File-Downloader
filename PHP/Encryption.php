<?php
function Encrypt($msg)
{
    $strlen = strlen($msg) - 1;
    for( $i = 0; $i <= $strlen; $i++ ) 
    {
        $letterAscii = ord($msg[$i]);
        $letterAscii += 3;
        $msg[$i] = chr($letterAscii);
    }
    return $msg;
}

function Decrypt($msg)
{
    $strlen = strlen($msg) - 1;
    for( $i = 0; $i <= $strlen; $i++) 
    {
        $letterAscii = ord($msg[$i]);
        $letterAscii -= 3;
        $msg[$i] = chr($letterAscii);
    }
    return $msg;
}
?>