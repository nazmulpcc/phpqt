<?php

$app = new \Qt\Widgets\Application();

$editor = new \Qt\Widgets\TextEdit;
$label = new \Qt\Widgets\Label("Hello World Foooo");
// $label->setText("Good Morning");
// $label->show();

$window = new \Qt\Widgets\MainWindow;
$window->setCentralWidget($label);

$button = new \Qt\Widgets\PushButton("Click Me", $window);

$window->show();

$app->exec();