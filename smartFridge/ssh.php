<?php

    $cli = 'python /home/pi/Desktop/get_barcode.py';
    $connection = ssh2_connect('tomtit.synology.me', 22);
    ssh2_auth_password($connection, 'pi', 'hfict');
    $stream = ssh2_exec($connection, $cli);
    //$errorStream = ssh2_fetch_stream($stream, SSH2_STREAM_STDERR);
    //stream_set_blocking($errorStream, true);
    //stream_set_blocking($stream, true);
    //$stream_out = ssh2_fetch_stream($stream, SSH2_STREAM_STDIO);
    $output = stream_get_contents($stream);
    fclose($stream);
    //fclose($errorStream);
    ssh2_exec($connection, 'exit');
    unset($connection);
    // return $output;
header('Location: add_remove.php');
?>