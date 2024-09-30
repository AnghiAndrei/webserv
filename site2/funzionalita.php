<!DOCTYPE html>
<html>
<head>
        <link rel="shortcut icon" href="./Assets/img/icona.jpg" type="image/x-icon">
        <link rel="stylesheet" type="text/css" href="./Assets/main.css">
        <meta charset="UTF-8">
        <meta http-equiv="x-ua-compatible" content="ie=8">
        <meta name="keywords" content="">
        <meta name="author" content="Andrei Anghi[Angly colui che regna]">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="copyright" content="Andrei Anghi[Angly colui che regna]">
        <title>Funzionalita | Wengly</title>
    </head>
    <body>
        <center>
            <div class="centro2">
                <h1 class="titolo">Funzionalita del Web Server</h1>
                <table>
                    <tr>
                        <td>
                            <h2 class="sottotitolo">Variabili POST</h2>
                            <form method="post">
                                <input name="post" type="text" value="<?php if(isset($_POST["post"])){echo$_POST["post"];}?>">
                                <button class="pulsanti">Invia</button>
                                <p class="sottotitolo">Valore: <?php if(isset($_POST["post"])){echo$_POST["post"];}?></p>
                            </form>
                        </td>
                        <td width="50px"><br></td>
                        <td>
                            <h2 class="sottotitolo">Variabili GET</h2>
                            <form method="get">
                                <input name="get" type="text" value="<?php if(isset($_GET["get"])){echo$_GET["get"];};?>">
                                <button class="pulsanti">Invia</button>
                                <p class="sottotitolo">Valore: <?php if(isset($_GET["get"])){echo$_GET["get"];};?></p>
                            </form>
                        </td>
                    </tr>
                </table>
                <hr class="linea">
                <p class="sottotitolod"><a class="link" href="index.html">Torna alla Home</a></p>
            </div>
        </center>
    </body>
</html>