<?php

$app = new \Qt\Widgets\Application();

$window = new \Qt\Widgets\MainWindow;
$window->setWindowTitle("Hello World");
$window->setGeometry(0, 100, 1000, 500);

$editor = new \Qt\Widgets\TextEdit("", $window);
$button = new \Qt\Widgets\PushButton("Click Me", $window);
$copyButton = new \Qt\Widgets\PushButton("Copy", $window);

$copyButton->onClicked(function () use($editor) {
    $editor->copy();
    echo "copied\n";
});
$button->onClicked(function () use($editor) {
    echo "Button\n";
});
$button->setGeometry(0, 0, 100, 50);
$copyButton->setGeometry(100, 0, 100, 50);
$editor->setGeometry(0, 50, 1000, 450);


$window->show();

$app->exec();
