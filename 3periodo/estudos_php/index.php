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
    
    function filter_by_author($books, $author){
        $author = gets.chomp
        $filtered_books = [];
        foreach ($books as $book){
            if ($book['author'] === $author ){
                $filtered_books[] = $book;
            }
        }
        return $filtered_books;
    }

    ?>

    <ul>
        <?php 
            foreach(filter_by_author($books, $author) as $book) : ?>
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
