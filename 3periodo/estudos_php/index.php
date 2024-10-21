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
        [
            'name' => 'Dracula',
            'author' => "Bram Stoker",
            'purchase_url' => "https://example.com"
        ],
        [
            'name' => "Carmilla, Karnstein's Vampire",
            'author' => "Sheridan Le Fanu",
            'purchase_url' => "https://example.com"
        ],    
        [
            'name' => "The Fall Of The House of Usher",
            'author' =>"Edgar Allan Poe",
            'purchase_url' => "https://example.com"

        ],
        [
            'name' => "Call of Cthulhu",
            'author' => "H.P. Lovecraft",
            'purchase_url' => "https://example.com"

        ]

       ];
    ?>
    <ul>
        <?php 
            foreach($books as $book) : ?>
                <li>
                    <a href ="<?= $book['purchase_url'] ?>">
                        <?= $book['name'] ?>
                    </a>
                </li>
            <?php endforeach; ?>
    </ul>

</body>
</html>
