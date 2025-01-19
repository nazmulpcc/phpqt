<?php

use Qt\Widgets\Application;
use Qt\Widgets\MainWindow;
use Qt\WebEngine\WebEngineView;
use Qt\Widgets\PushButton;


$app = new Application();
$window = new MainWindow();
$window->setWindowTitle('Hello World');

$button = new PushButton('Click me');
$view = new WebEngineView($window);
// $view->setUrl('https://google.com');

// $view->onLoadFinished(
//     fn() => $view->printToPdf(__DIR__ . '/google.pdf')
// );

// $view->onPdfPrintingFinished(fn() => $app->quit());

$window->setCentralWidget($button);
$window->show();
$app->exec();
