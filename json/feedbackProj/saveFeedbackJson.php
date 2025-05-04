<?php
// Set headers
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json");

// Get raw POST data
$input = file_get_contents("php://input");
$data = json_decode($input, true);

if (!$data) {
    http_response_code(400);
    echo json_encode(["message" => "Invalid JSON"]);
    exit;
}

// Load existing data
$file = 'feedback.json';
$feedback = [];

if (file_exists($file)) {
    $json = file_get_contents($file);
    $feedback = json_decode($json, true) ?: [];
}

// Append new feedback
$feedback[] = $data;

// Save updated array
file_put_contents($file, json_encode($feedback, JSON_PRETTY_PRINT));

// Send success response
echo json_encode([ 
    "message" => "Feedback saved successfully",
    "content" => $feedback
]);
?>
