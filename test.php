<?php

$app = new \Qt\Widgets\Application();


$window = new \Qt\Widgets\MainWindow;
$window->setWindowTitle("Hello World");
$window->setGeometry(0, 100, 1000, 500);
$window->setObjectName("MainWindow");

$layout = new \Qt\Widgets\FormLayout($window);
$layout->setObjectName("FormLayout");

$email = new \Qt\Widgets\LineEdit();
$password = new \Qt\Widgets\LineEdit();
$signIn = new \Qt\Widgets\PushButton("Log In");

var_dump($email === $email);

$password->setEchoMode(\Qt\Widgets\LineEdit::Password);

$signIn->onClicked(function () use($email, $password, $window) {
    $mail = $email->text();
    $password = $password->text();
    echo "Loggin In with {$mail} and {$password}\n";
    sleep(1);
    $window->close();
});

$layout->addRow("Email:", $email);
$layout->addRow("Password:", $password);
$layout->addRow($signIn);

$widget = new \Qt\Widgets\Widget();
$widget->setLayout($layout);

$window->setCentralWidget($widget);

$window->show();

$app->exec();
