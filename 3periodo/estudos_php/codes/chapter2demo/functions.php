<?php

function dumpNdie($value){
    echo "<pre>";
    var_dump($value);
    echo "</pre>";
    die();
}

function url_is($value){
    return $_SERVER['REQUEST_URI'] === $value;
}

function abort($code = 404){
    http_response_code($code);
    require "views/{$code}.php";
    die();
}

function route_to_controller($uri, $routes){
    if (array_key_exists($uri, $routes)){
        require $routes[$uri];
    } else {
        abort();
    }
}