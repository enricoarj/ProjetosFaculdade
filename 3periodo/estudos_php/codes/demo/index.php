
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

    require "index.view.php";
?>
