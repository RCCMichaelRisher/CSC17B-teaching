<?php
// Set headers
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/xml");

// Get raw POST data
$input = file_get_contents("php://input");
$xml = simplexml_load_string($input);

if (!$xml) {
    http_response_code(400);
    echo "<response><message>Invalid XML</message></response>";
    exit;
}

// Load existing data
$file = 'feedback.xml';
$feedback = new SimpleXMLElement('<feedbacks/>');

if (file_exists($file)) {
    $feedback = simplexml_load_file($file);
}

// Append new feedback
$newFeedback = $feedback->addChild('feedback');
foreach ($xml as $key => $value) {
    $newFeedback->addChild($key, htmlspecialchars($value));
}

// Save updated XML
$feedback->asXML($file);

// Send success response

$dom = dom_import_simplexml($feedback);
$contents =  $dom->ownerDocument->saveXML($dom->ownerDocument->documentElement);
echo "<response><message>Feedback saved successfully</message><content>{$contents}</content></response>";
?>
