<?php
    define( "DB_IP", "localhost");
    define( "DB_USER", "root");
    define( "DB_PASS", "");
    define( "DB_DB", "test");

    try{
        $connection = new PDO( "mysql:host=".DB_IP .";dbname=" . DB_DB, DB_USER, DB_PASS );
        //set the PDO error mode to exception
        $connection->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );
        
    } catch( Exception $e ){
        print_r( $e );
    }

    ?>