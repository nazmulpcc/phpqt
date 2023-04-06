<?php

$app = new \Qt\Widgets\Application();

$window = new \Qt\Widgets\MainWindow;
$window->setWindowTitle("Hello World");
$window->setGeometry(0, 100, 1000, 500);

$layout = new \Qt\Widgets\FormLayout($window);

$email = new \Qt\Widgets\LineEdit();
$password = new \Qt\Widgets\LineEdit();
$signIn = new \Qt\Widgets\PushButton("Log In");

$password->setEchoMode(\Qt\Widgets\LineEdit::Password);

$signIn->onClicked(function () use($email, $password, $window) {
    $mail = $email->text();
    $password = $password->text();
    echo "Loggin In with {$mail} and {$password}\n";
    sleep(5);
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
