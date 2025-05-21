<?php
    define( "DB_IP", "localhost");
    define( "DB_USER", "root");
    define( "DB_PASS", "");
    define( "DB_DB", "test");

    try{
        $connection = new mysqli( DB_IP, DB_USER, DB_PASS, DB_DB );
        if( $connection->errno > 0 ){
            echo "error connecting";
        }
        else {
            echo "connected";
        }
    } catch( Exception $e ){
        print_r( $e );
    }

    ?>