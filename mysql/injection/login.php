<?php
//Insecure code: for demonstration only

$host = "localhost";
$user = "root";
$pass = "";
$dbname = "test";

// Connect to MySQL
$conn = new mysqli($host, $user, $pass, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get input from URL (e.g. login.php?username=admin&password=123)
$username = $_GET['username'];
$password = $_GET['password'];

// Vulnerable query  user input directly embedded in SQL
$sql = "SELECT * FROM users WHERE username = '$username' AND password = '$password'";

echo "<p>Query: $sql</p>"; // Show the raw query for demonstration

$result = $conn->query($sql);

if ($result && $result->num_rows > 0) {
    echo "Logged in successfully!";
} else {
    echo "Invalid credentials.";
}

$conn->close();



//visit page
//http://localhost/login.php?username=admin&password=' OR '1'='1

?>