#include "functions.h"

QString caesarCipher(const QString message, int key) {
    QString encryptedMessage;
    for (QChar ch : message) {
        QChar encryptedChar = QChar( (ch.unicode() - 32 + key) % 96 + 32 );
        //if(encryptedChar.unicode() == 127) {
         //   encryptedChar = QChar(0);
        //}
        encryptedMessage.append(encryptedChar);
    }
    return encryptedMessage;
}

QString processInput(const QString& input) {
    // Разделяем строку на ключ и сообщение
    QStringList parts = input.split(' ', Qt::SkipEmptyParts);
    if (parts.size() < 2) {
        return "!Ошибка: неверный формат входной строки.";
    }
    // Получаем ключ и сообщение
    bool ok;
    int key = parts[0].toInt(&ok);
    if (!ok) {
        return "!Ошибка: ключ должен быть числом.";
    }

    QString message = parts.mid(1).join(' '); // Объединяем оставшиеся части в сообщение
    //QString message = parts[1];

    // Шифруем сообщение
    QString encryptedMessage = caesarCipher(message, key);

    // Возвращаем зашифрованное сообщение
    return QString("%1 \r\n%2").arg(input).arg(encryptedMessage);
}
