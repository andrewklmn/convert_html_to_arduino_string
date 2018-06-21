# HTML to Arduino string variable converter
This script converts HTML code to C++ string variables and adds arduino webserver answer command like this: 
## Source HTML code:
```
<html>
  <body>
    <h1><Header/h1>
    <p>some text</p>
  </body>
</html>
```

## Result Arduino code:
```
 String message0 = "<html> \
   <body> \
    <h1><Header/h1>";
    
 String message1 = <p>some text</p> \
  </body> \
</html> \
";

   server.setContentLength( 552 );
   server.send(200, "text/html", message0 );
   server.sendContent( message1 );
```
