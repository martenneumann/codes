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


bool tueEtwas(string& aktuellerZustand, string eingabe, eingabefehler fehlerBeiDerEingabe) {
    if (fehlerBeiDerEingabe == eingabefehler::nichtImEingabeAlphabet) {
        cout << "Es wurde ein Zeichen eingegeben, welches nicht im Eingabe-Alphabet liegt (" << eingabe << ")\n";
        return eingabefehlerErkannt;
    }
    if (fehlerBeiDerEingabe == eingabefehler::keinZeichenEingegeben) {
        cout << "Es wurde kein Zeichen eingegeben. Nur Enter grdruekt\n";
        return eingabefehlerErkannt;
    }
    if (fehlerBeiDerEingabe == eingabefehler::mehrAlsEinZeichenEingegeben) {
        cout << "Es wurde zwei oder mehr Zeichen auf einmal eingegeben (" << eingabe << ")\n";
        return eingabefehlerErkannt;
    }
    //----------------------------------------------------------------------------
    aktuellerZustand = zustandsUebergangTabelle[{aktuellerZustand, eingabe}]; // Hier passssiert die Magie
    cout << "Debugger - Aktuelles betrachtetes Zeichen (" << eingabe << ") Wo bin ich gerade -> (" << aktuellerZustand << ")\n";

    if (aktuellerZustand == "err") {
        cout << "Es wurde der err zustand der State Machine erreicht \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q101") {
        cout << "Eingegeben wurde ---> 1 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q102") {
        cout << "Eingegeben wurde ---> 2 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q103") {
        cout << "Eingegeben wurde ---> 3 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q104") {
        cout << "Eingegeben wurde ---> 4 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q105") {
        cout << "Eingegeben wurde ---> 5 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q106") {
        cout << "Eingegeben wurde ---> 6 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q107") {
        cout << "Eingegeben wurde ---> 7 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q108") {
        cout << "Eingegeben wurde ---> 8 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q109") {
        cout << "Eingegeben wurde ---> 9 \n";
        return endzustandErreicht;
    }
    if (aktuellerZustand == "Q110") {
        cout << "Eingegeben wurde ---> 10 \n";
        return endzustandErreicht;
    }

    return enzustandNichtErreicht;
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

eingabefehler checkeUserEingabe(const string& eingabe) {
    if (eingabe.size() == 0) return eingabefehler::keinZeichenEingegeben;
    if (eingabe.size() != 1) return eingabefehler::mehrAlsEinZeichenEingegeben;
    if (eingabe != "I" && eingabe != "V" && eingabe != "X" && eingabe != "#") return eingabefehler::nichtImEingabeAlphabet;
    return eingabefehler::keinEingabefehler;
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
    while (true){
        string aktuellerZustand = "Q0";

        cout << "--------------------------------------------------------------------------------------\n";
        cout << "Roemer Zahlen Converter \n";
        cout << "Gebe einen Buchstaben I, V, X ein. \n";
        cout << "Zum beenden # eingeben, dies symbolisiert das der letzte Buchstabe eingegeb wurde \n";
        cout << "--------------------------------------------------------------------------------------\n";

        // Schleife über jedes Zeichen der Eingabe
        while (true) {
            string eingabe = roemischeZahlVonTastaturEinlesen();
            eingabefehler fehlerBeiDerEingabe = checkeUserEingabe(eingabe);
            if (tueEtwas(aktuellerZustand, eingabe, fehlerBeiDerEingabe) == endzustandErreicht) break;
        }
    }
    return 0;
}