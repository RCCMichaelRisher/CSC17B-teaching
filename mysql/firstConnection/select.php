<?php

// phpinfo();

include_once( "connect.php" );

$result = $connection->query( "select * from table1");

debug( $result ); 




for( $i = 0; $i < $result->num_rows; $i++ ){
    $row = $result->fetch_assoc();
    echo "<p>{$row['id']}: {$row['name']}</p>";
}


foreach ($result as $row) {
    echo "<p>{$row['id']}: {$row['name']}</p>";
}


$arr = [];
foreach ($result as $row) {
    array_push( $arr, $row );
}


echo "array version";

$result->close();
debug( $arr );



function debug( $a ){
    echo "<pre>";
    print_r( $a );
    echo "</pre>";
}
?>