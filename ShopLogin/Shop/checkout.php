<?php # Script - checkout.php
// This page inserts the order information into the table.
// This page would come after the billing process.
// This page assumes that the billing process worked (the money has been taken).

// Set the page title and include the HTML header:
$page_title = 'Order Confirmation';
include('includes/header.html');

// Assume that the customer is logged in and that this page has access to the customer's ID:
$cid = 1; // Temporary.

// Assume that this page receives the order total:
$total = 178.93; // Temporary.

require('../mysqli_connect.php'); // Connect to the database.

// Turn autocommit off:
$dbc->autocommit(FALSE);

// Add the order to the orders table...
$q = "INSERT INTO orders (customer_id, total) VALUES (?, ?)";
$stmt = $dbc->prepare($q);
$stmt->bind_param('id', $cid, $total);
$stmt->execute();

if ($stmt->affected_rows == 1) {

    // Need the order ID:
    $oid = $dbc->insert_id;

    // Insert the specific order contents into the database...
    $q = "INSERT INTO order_contents (order_id, print_id, quantity, price) VALUES (?, ?, ?, ?)";
    $stmt = $dbc->prepare($q);

    // Execute each query; count the total affected:
    $affected = 0;
    foreach ($_SESSION['cart'] as $pid => $item) {
        $qty = $item['quantity'];
        $price = $item['price'];
        $stmt->bind_param('iiid', $oid, $pid, $qty, $price);
        $stmt->execute();
        $affected += $stmt->affected_rows;
    }

    // Report on the success...
    if ($affected == count($_SESSION['cart'])) { // Success!

        // Commit the transaction:
        $dbc->commit();

        // Clear the cart:
        unset($_SESSION['cart']);

        // Message to the customer:
        echo '<p>Thank you for your order. You will be notified when the items ship.</p>';

        // Send emails and do whatever else.

    } else { // Rollback and report the problem.

        $dbc->rollback();

        echo '<p>Your order could not be processed due to a system error. You will be contacted in order to have the problem fixed. We apologize for the inconvenience.</p>';
        // Send the order information to the administrator.

    }

} else { // Rollback and report the problem.

    $dbc->rollback();

    echo '<p>Your order could not be processed due to a system error. You will be contacted in order to have the problem fixed. We apologize for the inconvenience.</p>';
    // Send the order information to the administrator.

}

$stmt->close();
$dbc->close();

include('includes/footer.html');
?>