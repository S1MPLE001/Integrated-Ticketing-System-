<html>
<body bgcolor = teal>
 <center>
 <br>
 <br>
 <br>
 <br>
 <br><br><br><br><br>
 <h1><font color = "blue"><?php 
    $myfile = fopen("in.txt", "w") or die("Unable to open file!");
$txt = $_GET["name"];;
fwrite($myfile, $txt);
$nxt = "\n";
fwrite($myfile, $nxt);
$txt = $_GET["name1"];;
fwrite($myfile, $txt);
fwrite($myfile, $nxt);
fclose($myfile);
echo exec("project.exe") ; 
?><br>
</font></h1>
</center>
 </body>
</html>
