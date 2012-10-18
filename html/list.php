<?php
function read($file_location)
{
	$file = fopen($file_location, "r");

	while($c = fgets($file))
	{
	        echo $c;
	}

	fclose($file);
}
function add($file_location, $line)
{
	$file = fopen($file_location, "a");
	fwrite($file, "\n" . $line);
	fclose($file);
}
function remove($file_location, $line_number)
{
	$file = fopen($file_location, "r");
	$temp_string = ""; //To be written back to file
	$iterator = 0; //Counts the current line
	while($c = fgets($file))
	{
		if(!($iterator == $line_number))
		{
			$temp_string .= $c;
		}
		$iterator++;
	}
	fclose($file);
	$file = fopen($file_location, "w");
	fwrite($file, $temp_string);
	fclose($file);
}
$file_location = "list.dat";
if(isset($_GET['add']) && $_GET['add'] != "")
{
	add($file_location, $_GET['add']);
}
if(isset($_GET['del']) && $_GET['del'] != "")
{
	remove($file_location, $_GET['del']);
}
read($file_location);
?>
