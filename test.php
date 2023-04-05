<?php

$app = new \Qt\Widgets\Application();
$editor = new \Qt\Widgets\TextEdit;
$label = new \Qt\Widgets\Label("Hello World");
// $label->setText("Good Morning");
// $label->show();

$window = new \Qt\Widgets\MainWindow;
$window->setCentralWidget($editor);

$button = new \Qt\Widgets\PushButton("Click Me", $window);

// $button->onClicked(function (){
//     echo "Button Clicked\n";
// });

$button->onPressed(function () {
    echo "Button Pressed\n";
});

$button->onReleased(function () {
    echo "Button Released\n";
});

$window->show();

$app->exec();
