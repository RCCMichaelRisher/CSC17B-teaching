<?php
// Check if the POST parameters are set
if (isset($_POST['name']) && isset($_POST['email'])) {
  $name = htmlspecialchars($_POST['name']); // Sanitize the name input
  $email = htmlspecialchars($_POST['email']); // Sanitize the email input

  echo "<h1>Form Data Received</h1>";
  echo "<p><strong>Name:</strong> $name</p>";
  echo "<p><strong>Email:</strong> $email</p>";

  echo "<h2>JSON Data</h2>";
  // Create an associative array with the received data
  $data = array(
    'name' => $name,
    'email' => $email
  );
  echo "<pre>";
  // Encode the array to JSON format and display it
  echo json_encode($data, JSON_PRETTY_PRINT);
  echo "</pre>";
} else {
  echo "<p>No data received.</p>";
}
