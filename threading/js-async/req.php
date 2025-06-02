<?php
 sleep(1);
 header( 'Content-Type: application/json' );
 $re = [
    'status' => 'success',
    'message'=> 'This is dummy data',
    'timestamp' => time(),
 ];

 echo json_encode( $re );