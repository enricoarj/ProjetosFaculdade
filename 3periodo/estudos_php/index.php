<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Demo</title>
    
    <style>
        body{
            margin: 0;
            place-items: center;
            display: grid;
            font-family: sans-serif;
        }

    </style>

</head>
<body>
        
    <h1>
        Book Recomendations
    </h1>

    <?php 
       $books = [
        "Bram Stoker's Dracula",
        "Carmilla, Karnstein's Vampire",
        "Edgar Allan Poe",
        "H.P. Lovecraft"
       ];
    ?>
    <ul>
        <?php 
            foreach($books as $book) : ?>
                <li><?= $book ?></li>
            <?php endforeach; ?>
    </ul>

</body>
</html>
