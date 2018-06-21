<?php

define( 'SIZE_OF_PART' , 1200);

echo "=================================================\r\n";
echo " HTML Convertor to C char constant 1.0 (C) 2018\r\n";
echo "=================================================\r\n";

if ( $argc == 1  ) { 
    echo "Add html filename as parameter to convert to C char constant.\r\n";
    exit(0);
} else {
    if (file_exists($argv[1])) {
        $str=file_get_contents($argv[1]);
        /*
        $str = 'static const char html[] = "'.str_replace("\n", "\
\t", str_replace('"','\"',$str)).'\
";
';
         * 
         */
        $t = explode('.', $argv[1]);
        // Write to c file
  
        $parts = [];
        
        $length_str = strlen($str);
        echo 'Length of file: ',ceil($length_str)," bytes\r\n";
        
        $number_of_messages = $length_str/SIZE_OF_PART;
        echo 'It will be split to ',ceil($number_of_messages)," parts.\r\n";
        
        
        $vars = '';
        $length = '';
        $send_content = '';
        
        for ($i = 0; $i <= $number_of_messages; $i++) {
            $vars[$i] = "   String message".$i.";";
            $length[$i] = "message".$i.".length()";
            $parts[$i] = substr($str, SIZE_OF_PART * $i , SIZE_OF_PART);
            $parts[$i] = "\r\n   message".$i.' = "'.str_replace("\n","\
\t",str_replace('"','\"',str_replace("\\","\\\\",$parts[$i])))."\";\r\n";
            if ($i == 0 ) {
                $send_content = "   server.send(200, \"text/html\", message0 );\r\n";
            } else {
                $send_content .= "   server.sendContent( message".$i." );\r\n";
            };
        };
        
        
/*
  server.setContentLength( message1.length() + message2.length()+ message3.length()+ message4.length()+ message5.length()+ message6.length());
  server.send(200, "text/html", message1 );
  server.sendContent( message2 );
  server.sendContent( message3 );
  server.sendContent( message4 );
  server.sendContent( message5 );
  server.sendContent( message6 );
*/      
        
        file_put_contents($t[0].'.c', 
                implode($vars,"\r\n")."\r\n\r\n"
                .implode($parts, "")
                ."\r\n   server.setContentLength( "
                .$length_str." );\r\r\n"
                .$send_content 
        );
        echo "File ",$t[0],".c was writed.\r\n";
        exit(0);
            
    } else {
        echo "File ",$argv[1]," not exist.\r\n";
    };
    exit(0);
};

