<?php

$app = new \Qt\Widgets\Application();

$window = new \Qt\Widgets\MainWindow;
$window->setWindowTitle("Hello World");
$window->setGeometry(0, 100, 1000, 500);

$editor = new \Qt\Widgets\TextEdit("", $window);
$input = new \Qt\Widgets\LineEdit("", $window);
$button = new \Qt\Widgets\PushButton("Click Me", $window);
$copyButton = new \Qt\Widgets\PushButton("Copy", $window);

$copyButton->onClicked(function () use($editor) {
    $editor->copy();
    echo "copied\n";
});
$button->onClicked(function () use($input) {
    $input->setReadOnly(! $input->isReadOnly());
    $input->setSelection(0, 5);
});
$button->setGeometry(0, 0, 100, 50);
$copyButton->setGeometry(100, 0, 100, 50);
$input->setGeometry(0, 50, 1000, 100);
$input->setPlaceholderText("john@example.com");
// $input->setInputMask("0000-00-00");
$input->setMaxLength(8);


$window->show();

$app->exec();
