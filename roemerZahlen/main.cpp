#include "zustandstabelle.h"

// In der Datei automat.svg findet sich die Idee nach der dieses Programm gebaut wurde
// In der Datei uebergangstabelle.xlsx findet sich ein Ueberblick der Uebergaenge
// Nuetzliches Video fuer das grundverstaendniss -> https://www.youtube.com/watch?v=F5Dbr45rRR0

/** AUFGABENSTELLUNG
    Modellieren Sie einen deterministischen endlichen Automaten (DEA), der die römischen
    Zahlen (I, II, III, IV, V, VI, VII, VIII, IX, X, usw.) im Zahlenraum 1 bis 10 in arabische Ziffern
    (1,2,3,4,5,6,7,8,9,10 usw.) konvertiert.
    Ein Endezeichen für die Eingabe kann sein: „<Leerzeichen>“, „\“, „;“, “<Enter>“ usw.
    Erzeugen Sie anschließend die zugehörige Übergangstabelle und realisieren Sie ein
    entsprechendes Programm z.B. in C++ gemäß der im Unterricht besprochenen Anleitung.
    Passen Sie hierzu die Übergangstabelle des Beispielprogramms sowie die
    Eingabezeichenzuordnung und die Ausgabe entsprechend an.
    Das Programm muss nach dem Kompilieren ausführbar sein und die Übersetzung im
    Zahlenraum 1 bis 10 komplett erfüllen.
    Ihre Arbeitsergebnisse sichern Sie auf IServ in einem Ordner mit Ihrem Namenskürzel unter:
**/


/**
 * @brief  Gibt das Ergebnis des Automaten auf der Konsole aus.
 *
 * Diese Funktion gibt entweder die arabische Zahl für den erreichten Endzustand
 * oder eine passende Fehlermeldung aus, wenn die Eingabe ungültig war.
 *
 * @param[in] endzustand
 *      Der letzte Zustand, den der Automat erreicht hat.
 *      Gültige Werte sind "Q1" bis "Q10".
 *      Bei ungültiger römischer Zahl (z. B. "IIX") wird "err" übergeben und
 *      als Fehlermeldung auf die Konsole ausgegeben.
 *
 * @param[in] eingabefehler
 *      Gibt an, ob die Benutzereingabe Zeichen enthält, die nicht zum
 *      Eingabealphabet des Automaten gehören (also nicht 'I', 'V' oder 'X').
 *      In diesem Fall wird ebenfalls eine Fehlermeldung ausgegeben.
 *
 * @return
 *      Diese Funktion liefert keinen Rückgabewert. Fehler oder Ergebnisse
 *      werden direkt auf der Konsole ausgegeben. Das Programm läuft anschließend
 *      weiter und wartet auf die nächste Eingabe.
 */

void gebeLoesungAus(string endzustand, bool eingabefehler) {
    cout << "Debugger - Finaler zustand -> (" << endzustand << ")\n";
    if (eingabefehler) {
        cout << "\033[31mIrgend etwas eingegeben, was nicht dem Eingabe-Alphabet entspricht\033[0m" << std::endl;
    } else if (endzustand == "err") {
        cout << "\033[31mKeine richtige römische Zahl zwischen I - X\033[0m" << std::endl;
    } else {
        cout << "\033[32mDie arabische Nummer ist -> " << endzustaende.at(endzustand) << "\033[0m" << std::endl;
    }
    cout << "-------------------------------------------------\n";
}

/**
 * @brief Liest eine römische Zahl von der Tastatur ein.
 *
 * Diese Funktion fordert den Benutzer auf, eine römische Zahl einzugeben
 * und liest die komplette Zeile von der Konsole ein. Es werden keine
 * Validierungen durchgeführt – beliebige Zeichen werden akzeptiert.
 *
 * @return std::string
 *      Die vom Benutzer eingegebene Zeichenkette.
 */
string roemischeZahlVonTastaturEinlesen() {
    cout << "RoemerZahl eingabe: ";
    string eingabe;
    getline(cin, eingabe);
    return eingabe;
}

/**
 * @brief Hauptprogramm zur Konvertierung römischer Zahlen in arabische Zahlen.
 *
 * Das Programm läuft in einer Endlosschleife und verarbeitet Benutzereingaben.
 * Es liest römische Zahlen von der Tastatur ein, überprüft, ob nur gültige
 * Zeichen ('I', 'V', 'X') verwendet wurden, und ermittelt den Endzustand
 * des Automaten anhand einer Zustands-Tabelle.
 *
 * Je nach Ergebnis wird entweder die entsprechende arabische Zahl oder eine
 * Fehlermeldung auf der Konsole ausgegeben. Debug-Informationen zu jedem
 * betrachteten Zeichen und Zustand werden ebenfalls angezeigt.
 *
 * Der Unterstützte Zahlenraum ist zwichen 1 - 10 bzw I - X
 *
 * @return int
 *      Gibt 0 zurück, wenn das Programm regulär beendet wird (Endlosschleife
 *      verhindert normalerweise eine Rückgabe während des laufenden Programms).
 */
int main() {
    while (1){
        string aktuellerZustand = "Q0";
        string eingabe = roemischeZahlVonTastaturEinlesen();
        bool eingabefehler = false;

        // Schleife über jedes Zeichen der Eingabe
        for (auto aktuellesZeichen_it = eingabe.begin(); aktuellesZeichen_it != eingabe.end(); ++aktuellesZeichen_it) {
            string eingabeZeichenAlsString(1, char(*aktuellesZeichen_it));
            if (eingabeZeichenAlsString != "I" && eingabeZeichenAlsString != "V" && eingabeZeichenAlsString != "X") eingabefehler = true;
            cout << "Debugger - Aktuelles betrachtetes Zeichen (" << eingabeZeichenAlsString << ") Wo bin ich gerade -> (" << aktuellerZustand << ")\n";
            aktuellerZustand = zustandsTabelle[{aktuellerZustand, eingabeZeichenAlsString}]; // Hier passssiert die Magie

            /**-----------------------------------------------------------------------------------
             * Für den fall, dass auch auf den "Zwischenzuständen" eine Aktion ausgeführt werden sollte,
             * könnte man das hier Implementieren. In unseren Fall interessiert uns nur der Endzustand.
             * D.h. interessieren wir uns an dieser stelle nicht für den "Pfad" durch den Automaten
             *
             * if (aktuellerZustand  == "Q1") {
             *   cout << "wir sind in Q1\n";
             * }
             * if (aktuellerZustand  == "Q2") {
             *    cout << "wir sind in Q2\n";
             * }
             * ...
             * if (aktuellerZustand  == "Q10") {
             *    cout << "wir sind in Q10\n";
             * }
             * if (aktuellerZustand  == "err") {
             *    cout << "wir sind in err\n";
             * }
             * ----------------------------------------------------------------------------------- */
        }
        gebeLoesungAus(aktuellerZustand, eingabefehler);
    }
    return 0;
}