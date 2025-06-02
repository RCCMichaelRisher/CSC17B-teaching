<?php # Script 19.x - mysqli_connect.php
// This file contains the database access information. 
// This file also establishes a connection to MySQL 
// and selects the database.

// Set the database access information as constants:
DEFINE('DB_USER', 'root');
DEFINE('DB_PASSWORD', '');
DEFINE('DB_HOST', 'localhost');
DEFINE('DB_NAME', 'shop');

// Create a new MySQLi object for the connection:
$dbc = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);

// Check for a connection error:
if ($dbc->connect_error) {
    die('Could not connect to MySQL: ' . $dbc->connect_error);
}

// Set the encoding...
$dbc->set_charset('utf8');