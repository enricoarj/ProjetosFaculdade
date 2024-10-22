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
            'purchase_url' => "https://example.com",
            'release_date' =>  1992
        ],
        [
            'name' => "Carmilla, Karnstein's Vampire",
            'author' => "Sheridan Le Fanu",
            'purchase_url' => "https://example.com",
            'release_date' => 1872
        ],    
        [
            'name' => "The Fall Of The House of Usher",
            'author' =>"Edgar Allan Poe",
            'purchase_url' => "https://example.com",
            'release_date' => 1839
        ],
        [
            'name' => "Call of Cthulhu",
            'author' => "H.P. Lovecraft",
            'purchase_url' => "https://example.com",
            'release_date' => 1981
        ]

       ];
/*
    function filter($items, $fn){

        $filtered_items = [];

        foreach ($items as $item){
            if ($fn($item)){
                $filtered_items[] = $item;
            }
        }
        return $filtered_items;
    }
*/

    $filtered_books = array_filter($books, function($book){
        return $book['release_date'] < 1900;
    });

    ?>

    <ul>
        <?php 
            foreach($filtered_books as $book) : ?>
                    <li>
                        <a href ="<?= $book['purchase_url'] ?>">
                            <?= $book['name'] ?> (<?= $book['release_date']?>)
                        </a>
                    </li>
            <?php endforeach; ?>
    </ul>
    <p>
    </p>
</body>
</html>
