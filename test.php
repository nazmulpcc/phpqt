<?php

namespace Qt\Core;
if (!class_exists(\Qt\Core\Obj::class)) {
    class Obj {
        public function setObjectName(string $name) {}
        public function onObjectNameChanged(callable $callback) {}
        public function startTimer(int $interval, callable|int $timerType, callable $callback = null) {}
    }
}

namespace Qt\Widgets;
if (!class_exists(\Qt\Widgets\Layout::class)) {
    class Layout extends \Qt\Core\Obj {
        public function __construct(\Qt\Core\Obj $parent) {
            //
        }
        public function addRow(\Qt\Core\Obj|string $label, \Qt\Core\Obj $row = null) {}
    }
    class Widget extends \Qt\Core\Obj {
        public function close() {}
        public function show() {}
        public function setLayout(\Qt\Widgets\Layout $layout) {}
        public function setWindowTitle(string $title) {}
        public function setCentralWidget(\Qt\Widgets\Widget $widget) {}
        public function setGeometry(int $x, int $y, int $w, int $h) {}
    }
    class Application extends Widget {
        public function exec() {}
    }
    class MainWindow extends Widget {}
    class FormLayout extends Layout {}
    class LineEdit extends Widget {
        const Normal = 0;
        const NoEcho = 1;
        const Password = 2;
        const PasswordEchoOnEdit = 3;
        public function setEchoMode(int $mode){}
        public function setPlaceholderText(int $mode){}
        public function text(){}
    }
    class PushButton extends Widget {
        public function onPressed(callable $callback){}
        public function onReleased(callable $callback){}
        public function onClicked(callable $callback){}
    }
}

$app = new \Qt\Widgets\Application();

$window = new \Qt\Widgets\MainWindow;
$window->setWindowTitle("Hello World");
$window->setGeometry(0, 100, 600, 300);

$layout = new \Qt\Widgets\FormLayout($window);
$layout->setObjectName("FormLayout");

$email = new \Qt\Widgets\LineEdit();
$password = new \Qt\Widgets\LineEdit();
$signIn = new \Qt\Widgets\PushButton("Log In");

$email->setPlaceholderText("jhon@example.com");
$password->setPlaceholderText("super secret");
$password->setEchoMode(\Qt\Widgets\LineEdit::Password);

$signIn->onClicked(function () use($email, $password, $window) {
    $mail = $email->text();
    $password = $password->text();
    echo "Loggin In with {$mail} and {$password}\n";
    $window->startTimer(1000, fn() => $window->close());
});

$layout->addRow($email);
$layout->addRow($password);
$layout->addRow($signIn);

$widget = new \Qt\Widgets\Widget();
$widget->setLayout($layout);

$window->setCentralWidget($widget);

$thread = new \Qt\Core\Thread;
$thread->onStarted(function () use(&$thread) {
    echo "Thread has started\n";
    sleep(5);
    echo "Thread work done\n";
    $thread->exit(0);
});
$thread->onFinished(function () {
    echo "Thread finished\n";
});
$thread->start();

$window->show();

$app->exec();
