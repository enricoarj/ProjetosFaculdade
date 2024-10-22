
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
