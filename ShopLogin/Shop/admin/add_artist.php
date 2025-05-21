<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add an Artist</title>
    <link rel="stylesheet" href="../../styles.css"> <!-- Link to an external stylesheet -->
</head>
<body>
<?php # Script - add_artist.php
// This page allows the administrator to add an artist.

if ($_SERVER['REQUEST_METHOD'] == 'POST') { // Handle the form.
    
    // Validate the first and middle names (neither required):
    $fn = (!empty($_POST['first_name'])) ? trim($_POST['first_name']) : NULL;
    $mn = (!empty($_POST['middle_name'])) ? trim($_POST['middle_name']) : NULL;

    // Check for a last_name...
    if (!empty($_POST['last_name'])) {
        
        $ln = trim($_POST['last_name']);
        
        // Add the artist to the database:
        require ('../../mysqli_connect.php');
        $q = 'INSERT INTO artists (first_name, middle_name, last_name) VALUES (?, ?, ?)';
        $stmt = $dbc->prepare($q);
        $stmt->bind_param('sss', $fn, $mn, $ln);
        $stmt->execute();
        
        // Check the results....
        if ($stmt->affected_rows == 1) {
            echo '<p>The artist has been added.</p>';
            $_POST = array();
        } else { // Error!
            $error = 'The new artist could not be added to the database!';
        }
        
        // Close this prepared statement:
        $stmt->close();
        $dbc->close(); // Close the database connection.
        
    } else { // No last name value.
        $error = 'Please enter the artist\'s name!';
    }
    
} // End of the submission IF.

// Check for an error and print it:
if (isset($error)) {
    echo '<h1>Error!</h1>
    <p style="font-weight: bold; color: #C00">' . $error . ' Please try again.</p>';
}

// Display the form...
?>
<h1>Add an Artist</h1>
<form action="add_artist.php" method="post">
    <fieldset>
        <legend>Fill out the form to add an artist:</legend>
        
        <label for="first_name"><b>First Name:</b></label>
        <input type="text" id="first_name" name="first_name" size="20" maxlength="20" value="<?php if (isset($_POST['first_name'])) echo htmlspecialchars($_POST['first_name']); ?>" />
        
        <label for="middle_name"><b>Middle Name:</b></label>
        <input type="text" id="middle_name" name="middle_name" size="20" maxlength="20" value="<?php if (isset($_POST['middle_name'])) echo htmlspecialchars($_POST['middle_name']); ?>" />
        
        <label for="last_name"><b>Last Name:</b></label>
        <input type="text" id="last_name" name="last_name" size="40" maxlength="40" value="<?php if (isset($_POST['last_name'])) echo htmlspecialchars($_POST['last_name']); ?>" />
    </fieldset>
        
    <div style="text-align: center;">
        <input type="submit" name="submit" value="Submit" />
    </div>
</form>

</body>
</html>