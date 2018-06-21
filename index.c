   String message0;
   String message1;
   String message2;
   String message3;
   String message4;
   String message5;
   String message6;
   String message7;
   String message8;
   String message9;
   String message10;
   String message11;
   String message12;


   message0 = "<!DOCTYPE html>\
	<html>\
	    <head>\
	        <title>Buzantipe Dew</title>\
	        <meta charset=\"UTF-8\">\
	        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\
	        <link rel=\"stylesheet\" href=\"http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.css\" />\
	        <script src=\"http://code.jquery.com/jquery-1.11.1.min.js\"></script>\
	        <script src=\"http://code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.js\"></script>\
	        <script>\
	\
	var active_tap = '';\
	var message = '';\
	var irrigation_disabled= 1;\
	var night_is_on = -1;\
	var working_time = [0,0,0,0];\
	var default_time = [0,0,0,0];\
	var total_time = 0;\
	\
	var timeout;\
	var timeout1;\
	var timeout2;\
	var timeout3;\
	            \
	/*var api = 'http://192.168.0.201/api';*/\
	api = '/api';\
	            \
	$( document ).ready(function (){\
	    \
	    get_current_status();\
	    get_default_time();\
	    \
	    \
	    $( \"button.starter\" ).bind( \"click\", function() {\
	        var id = $(this).html();\
	        var span = $('span#w' + id);\
	        var span_regulator = $('span#t' + ( parseInt(id) - 1));\
	        \
	        \
	        if($(this).hasClass('ui-btn-active')) {\
	            $(span).html(0);\
	            $(this).removeClass('ui-b";

   message1 = "tn-active');\
	            send_command(\"AT C\" + id);\
	        } else {\
	            $(span).html($(span_regulator).html());\
	            $(this).addClass('ui-btn-active');\
	            send_command(\"AT O\" + id);\
	        };\
	    });\
	    \
	    $( \"input.regulator\" ).bind( \"click\", function() {\
	        var id = parseInt(this.id);\
	        var span = $('span#t' + ( id - 1));\
	        var t = parseInt($(span).html());\
	        send_command(\"AT \" + this.value + this.id);\
	        if (this.value == '+') {\
	            $(span).html(t + 60);\
	        } else {\
	            $(span).html(((t - 60) >= 0)?(t - 60):0);\
	        };\
	    });\
	});\
	\
	\
	function send_command(command){\
	    $.ajax({\
	      type: \"POST\",\
	      data: { command: command },\
	      url: api,\
	      success: function( data ) {\
	        show_status( data.answer);\
	      },\
	      error: function () {\
	        show_status( \"<font style='color:red;'>Connection error!</font>\" );\
	      },\
	      dataType: \"json\"\
	    });    \
	};\
	\
	function get_current_status(){\
	    \
	    clearTimeout(timeout1);\
	    \
	    $.ajax({\
	      type: \"POST\",\
	      data: { command: \"AT S\" },\
	      url: api,\
	      success: function( data ) {\
	        \
	        if(data.answer==\"T\") {\
	        ";

   message2 = "    show_status( \"<font style='color:red;'>PIC timeout error!</font>\" );\
	            timeout1 = setTimeout( get_current_status ,1000);\
	            return true;\
	        };\
	        \
	        var t = data.answer.split('|');\
	        \
	        working_time = [ parseInt(t[2]),parseInt(t[3]),parseInt(t[4]),parseInt(t[5]) ];\
	        \
	        var time_before = 0;\
	        \
	        for ( var i = 2; i < 6; i++ ) {\
	            $('span#w' + (i - 1) ).html( working_time[i-2] );\
	            var button = $('button#b' + (i-1));\
	            if ( working_time[i-2] > 0 && time_before == 0  ) {\
	                if (!$(button).hasClass('ui-btn-active')) {\
	                    $(button).addClass('ui-btn-active');\
	                };\
	            } else {\
	                if ($(button).hasClass('ui-btn-active')) {\
	                    $(button).removeClass('ui-btn-active');\
	                };\
	            };\
	            time_before += working_time[i-2];\
	        };\
	        \
	        \
	        if ( irrigation_disabled == t[1]) {\
	            \
	        } else {\
	            irrigation_disabled = t[1];\
	            if ( irrigation_disabled == '0') {\
	                $('select#switch_auto_mode').val(\"on\").slider( \"refresh\" );\
	";

   message3 = "                $('div#automode_settings').show();\
	            } else {\
	                $('select#switch_auto_mode').val(\"off\").slider( \"refresh\" );\
	                $('div#automode_settings').hide();\
	            };            \
	        };\
	        \
	        \
	        \
	        if (night_is_on == t[0] ) {\
	            \
	        } else {\
	            night_is_on = t[0];\
	            if (night_is_on == 1) {\
	                $('.ui-body-a').removeClass('ui-body-a').addClass('ui-body-b');\
	                $('.ui-btn-b').removeClass('ui-btn-b').addClass('ui-btn-a');\
	            } else {\
	                $('.ui-body-b').removeClass('ui-body-b').addClass('ui-body-a');\
	                $('.ui-btn-a').removeClass('ui-btn-a').addClass('ui-btn-b');\
	            };            \
	        };\
	\
	        total_time = parseInt(working_time[0]) \
	                + parseInt(working_time[1]) \
	                + parseInt(working_time[2]) \
	                + parseInt(working_time[3]); \
	        if(total_time > 0) {\
	            show_status('Watering ON<br/> ' + Math.round(total_time) + ' sec left.');\
	        } else {\
	            clearTimeout(timeout3);\
	            timeout3 = setTimeout(function(){show_status('');},1000 );\
	    ";

   message4 = "    };\
	        timeout1 = setTimeout( get_current_status ,1000);\
	      },\
	      error: function () {\
	        show_status( \"<font style='color:red;'>Connection error!</font>\" );\
	        timeout1 = setTimeout( get_current_status ,1000);\
	      },\
	      dataType: \"json\"\
	    });\
	};\
	\
	function get_default_time(){\
	        \
	    clearTimeout(timeout2);\
	\
	    $.ajax({\
	      type: \"POST\",\
	      data: { command: \"AT T\" },\
	      url: api,\
	      success: function( data ) {\
	        \
	        if(data.answer==\"T\") {\
	            show_status( \"<font style='color:red;'>PIC timeout error!</font>\" );\
	            timeout2 = setTimeout( get_default_time ,1000);\
	            return true;\
	        };\
	          \
	        var t = data.answer.split('|');\
	        \
	        \
	        for ( var i = 0; i < 4; i++ ) {\
	            if( t[i] === default_time[i] ) {\
	                \
	            } else {\
	                default_time[i]=t[i];\
	                $('span#t' + i ).html(default_time[i]);\
	            };\
	        };\
	        timeout2 = setTimeout( get_default_time ,1000);\
	      },\
	      error: function () {\
	        show_status( \"<font style='color:red;'>Connection error!</font>\" );\
	        timeout2 = setTimeout( get_defaul";

   message5 = "t_time ,1000);\
	      },\
	      dataType: \"json\"\
	    });\
	};\
	\
	\
	\
	\
	\
	\
	            function tap_countdown(){\
	                var elem = $('span#timer');\
	                var timer = parseInt($(elem).html());\
	                if (timer == 0) {\
	                    $('input.tap').attr(\"checked\",false).checkboxradio(\"refresh\");\
	                    $('div#timer').hide();\
	                    $('div#status').html('All taps closed');\
	                    active_tap = '';\
	                    return true;\
	                } else {\
	                    $(elem).html( timer - 1 );\
	                    timeout = setTimeout( tap_countdown , 1000);\
	                };\
	            };\
	            \
	            function switch_auto_mode() {\
	                if ( irrigation_disabled == 1 ) {\
	                    irrigation_disabled = 0;\
	                    send_command('AT E');\
	                    $('div#automode_settings').show();\
	                } else {\
	                    irrigation_disabled = 1;\
	                    send_command('AT D');\
	                    $('div#automode_settings').hide();\
	                };\
	            };\
	            \
	            \
	            function show_status(message) {\
	                $('d";

   message6 = "iv#status').html(message);\
	            }\
	            \
	            function tap_select(elem) {\
	                if (active_tap == $(elem).val()) {\
	                    active_tap = '';\
	                    $(elem).attr(\"checked\",false);\
	                    $('div#timer').hide();\
	                    $('div#status').html('All taps closed');\
	                } else {\
	                    active_tap = $(elem).val();\
	                    $(elem).attr(\"checked\",true);\
	                    $('div#timer').show();\
	                    $('div#status').html('Tap ' + (parseInt(active_tap)+1) + ' opened');\
	                    if (default_time[active_tap] < 60) {\
	                        $('span#timer').html(60);\
	                    } else {\
	                        $('span#timer').html(default_time[active_tap]);\
	                    };\
	                    clearTimeout(timeout);\
	                    tap_countdown();\
	                };\
	                \
	            };\
	                        \
	        </script>\
	        <style>\
	            .timer{\
	                font-size: 1.8em;\
	            }\
	            .header{\
	                font-size: 1.2em;\
	            }\
	            .shower{\
	                font-size: 1.";

   message7 = "6em;\
	                color:gray;\
	            }\
	        </style>\
	    </head>\
	    <body style=\"text-align: center;\" class=\"ui-body-b ui-body\">\
	        <div class=\"ui-body-b ui-body\">\
	            <div data-role=\"footer\" data-position=\"fixed\" style=\"height: 40px;\">\
	                <a href='command' class=\"ui-btn ui-btn-icon-notext ui-icon-gear\">command mode</a>\
	            </div><!-- /footer -->\
	            <div class=\"ui-grid-solo\">\
	                <span class=\"header\">Current taps status:</span>\
	            </div>\
	            <div class=\"ui-grid-c\">\
	                <div class=\"ui-block-a\">\
	                    <button id=\"b1\" class=\"ui-btn ui-btn-a ui-btn-corner-all starter\">1</button>\
	                </div>      \
	                <div class=\"ui-block-b\">\
	                    <button id=\"b2\" class=\"ui-btn ui-btn-a ui-btn-corner-all starter\">2</button>\
	                </div>      \
	                <div class=\"ui-block-c\">\
	                    <button id=\"b3\" class=\"ui-btn ui-btn-a ui-btn-corner-all starter\">3</button>\
	                </div>      \
	                <div class=\"ui-block-d\">\
	                    <button id=\"b4\" class=\"ui-btn ui-btn-a ui-btn-corner-all starter\">4</button>\
	       ";

   message8 = "         </div>      \
	            </div><!-- /grid-c -->\
	            \
	            <div class=\"ui-grid-c\">\
	                <div class=\"ui-block-a\">\
	                    <span class=\"timer\" id=\"w1\"></span>\
	                </div>      \
	                <div class=\"ui-block-b\">\
	                    <span class=\"timer\" id=\"w2\"></span>\
	                </div>      \
	                <div class=\"ui-block-c\">\
	                    <span class=\"timer\" id=\"w3\"></span>\
	                </div>      \
	                <div class=\"ui-block-d\">\
	                    <span class=\"timer\" id=\"w4\"></span>\
	                </div>      \
	            </div><!-- /grid-c -->\
	            <hr/> \
	            <div class=\"ui-grid-solo\">\
	                <span class=\"header\">Autowatering:</span>\
	                <br/>\
	                <select onchange=\"switch_auto_mode(this);\" \
	                        name=\"switch_auto_mode\" \
	                        id=\"switch_auto_mode\" \
	                        data-role=\"slider\">\
	                        <option value=\"off\">Off</option>\
	                        <option value=\"on\">On</option>\
	                </select>\
	            </div>\
	            <div class=\"ui-grid-solo\">\
	                <div ";

   message9 = "id=\"automode_settings\" style=\"display: none;text-align: center;\">\
	                    <div class=\"ui-grid-solo\">\
	                        Default period of Autowatering:\
	                    </div>\
	                    <div class=\"ui-grid-c\">\
	                         <div class=\"ui-block-a\">\
	                            <div class=\"ui-bar ui-bar-a\" style=\"text-align: center;\">\
	                                <div class=\"ui-grid-solo\">\
	                                    <input id=\"1\" class=\"ui-btn regulator\" type=\"button\" value=\"+\"/>\
	                                </div>\
	                                <div class=\"ui-grid-solo\">\
	                                    <span id=\"t0\">0</span>\
	                                </div>\
	                                <div class=\"ui-grid-solo\">\
	                                    <input id=\"1\" class=\"ui-btn regulator\" type=\"button\" value=\"-\"/>\
	                                </div> \
	                            </div>\
	                        </div>\
	                         <div class=\"ui-block-b\">\
	                            <div class=\"ui-bar ui-bar-a\" style=\"text-align: center;\">\
	                                <div class=\"ui-grid-solo\">\
	       ";

   message10 = "                             <input id=\"2\" class=\"ui-btn regulator\" type=\"button\" value=\"+\"/>\
	                                </div>\
	                                <div class=\"ui-grid-solo\">\
	                                    <span id=\"t1\">0</span>\
	                                </div>\
	                                <div class=\"ui-grid-solo\">\
	                                    <input id=\"2\" class=\"ui-btn regulator\" type=\"button\" value=\"-\"/>\
	                                </div> \
	                            </div>\
	                        </div>\
	                         <div class=\"ui-block-c\">\
	                            <div class=\"ui-bar ui-bar-a\" style=\"text-align: center;\">\
	                                <div class=\"ui-grid-solo\">\
	                                    <input id=\"3\" class=\"ui-btn regulator\" type=\"button\" value=\"+\"/>\
	                                </div>\
	                                <div class=\"ui-grid-solo\">\
	                                    <span id=\"t2\">0</span>\
	                                </div>\
	                                <div class=\"ui-grid-solo\">\
	                                    <input id=\"3\" class=\"ui-btn regulator\" type=\"button\" valu";

   message11 = "e=\"-\"/>\
	                                </div> \
	                            </div>\
	                        </div>\
	                         <div class=\"ui-block-d\">\
	                            <div class=\"ui-bar ui-bar-a\" style=\"text-align: center;\">\
	                                <div class=\"ui-grid-solo\">\
	                                    <input id=\"4\" class=\"ui-btn regulator\" type=\"button\" value=\"+\"/>\
	                                </div>\
	                                <div class=\"ui-grid-solo\">\
	                                    <span id=\"t3\">0</span>\
	                                </div>\
	                                <div class=\"ui-grid-solo\">\
	                                    <input id=\"4\" class=\"ui-btn regulator\" type=\"button\" value=\"-\"/>\
	                                </div> \
	                            </div>\
	                        </div>\
	                    </div>\
	                    <div class=\"ui-grid-c\">\
	                        <div class=\"ui-block-a header\">\
	                            Tap 1\
	                        </div>\
	                        <div class=\"ui-block-b header\">\
	                            Tap 2\
	                        </div>\
	               ";

   message12 = "         <div class=\"ui-block-c header\">\
	                            Tap 3\
	                        </div>\
	                        <div class=\"ui-block-d header\">\
	                            Tap 4\
	                        </div>\
	                    </div>\
	                </div>\
	            </div>\
	            <hr/>\
	            <div id=\"status\" class=\"shower ui-grid-a\" style=\"height: 320px;text-align: center;\">\
	                App is starting...\
	            </div>\
	        </div>\
	    </body>\
	</html>";

   server.setContentLength( 14899 );
   server.send(200, "text/html", message0 );
   server.sendContent( message1 );
   server.sendContent( message2 );
   server.sendContent( message3 );
   server.sendContent( message4 );
   server.sendContent( message5 );
   server.sendContent( message6 );
   server.sendContent( message7 );
   server.sendContent( message8 );
   server.sendContent( message9 );
   server.sendContent( message10 );
   server.sendContent( message11 );
   server.sendContent( message12 );
