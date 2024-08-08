<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "robot_controller";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Query to fetch the last command
$sql = "SELECT RobotDirections FROM commands ORDER BY Id DESC LIMIT 1";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Output the last command
    $row = $result->fetch_assoc();
    $direction = htmlspecialchars($row['RobotDirections']);
    echo "<p>Last command: $direction</p>";
} else {
    echo "<p>No commands found</p>";
}

$conn->close();
?>
