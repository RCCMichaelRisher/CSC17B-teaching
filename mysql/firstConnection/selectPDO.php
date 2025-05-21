<?php

// phpinfo();

include_once( "connectPDO.php" );

$result = $connection->query( "select * from table1");

debug( $result ); 

while( $row = $result->fetch() ) {
    echo $row['id'] .' n:'. $row['name'] . '<br>';;
}






function debug( $a ){
    echo "<pre>";
    print_r( $a );
    echo "</pre>";
}
?>