<?php
interface Observer {
    public function update($message);
}

class Logger implements Observer {
    public function update($message) {
        file_put_contents('log.txt', $message . "\n", FILE_APPEND);
    }
}
?>
