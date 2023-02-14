# ESP8266 REST API Server
Questo codice fornisce una soluzione semplice e pronta all'uso per creare un web server REST API su un ESP8266 connesso a un lettore microSD. L'API fornisce endpoint per la lettura e la scrittura di file sulla scheda microSD tramite richieste HTTP.

## Requisiti
- ESP8266
- Lettore microSD
- Conoscenza di base di C e programmazione di microcontrollori
- Conoscenza di base di REST API e HTTP

## Caratteristiche
- Endpoint per la lettura e la scrittura di file su scheda microSD
- Interfaccia semplice e intuitiva per l'utilizzo dell'API tramite richieste HTTP
- Pagina di benvenuto con informazioni sulle funzionalità dell'API
- Codice facile da modificare e personalizzare per le proprie esigenze

## Uso
Per utilizzare questo codice, è necessario prima caricare il codice sul microcontrollore ESP8266 e quindi avviare il web server. L'API sarà quindi accessibile tramite richieste HTTP al seguente indirizzo IP: `http://<ESP8266_IP>/`.

La pagina di benvenuto fornisce informazioni sulle funzionalità dell'API e su come utilizzarle.

## Endpoint
Questo codice fornisce i seguenti endpoint per l'utilizzo dell'API:

- `GET /`: Pagina di benvenuto con informazioni sulle funzionalità dell'API.
- `GET /file`: Endpoint per la lettura di un file dalla scheda microSD. È necessario passare il nome del file come argomento `filename` nella richiesta. Ad esempio: `http://<ESP8266_IP>/file?filename=example.txt`.
- `PUT /file`: Endpoint per la scrittura di un file sulla scheda microSD. È necessario passare il nome del file come argomento `filename` nella richiesta e il contenuto del file nel corpo della richiesta. Ad esempio: `http://<ESP8266_IP>/file?filename=example.txt` con il contenuto del file nel corpo della richiesta.

## Modifiche e personalizzazioni
Questo codice è facile da modificare e personalizzare per le proprie esigenze. Ad esempio, è possibile aggiungere o modificare endpoint, modificare la gestione degli errori o personalizzare la pagina di benvenuto.

## Riferimenti
- [ESP8266WiFi Library](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
- [ESP8266WebServer Library](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer)
- [SD Library](https://github.com/esp8266/Arduino/tree/master/libraries/SD)

Per ulteriori informazioni e supporto, si prega di consultare la documentazione ufficiale delle librerie e la comunità online dedicata all'ESP8266.

## Note finali
Questo codice è fornito così com'è, senza garanzie di alcun tipo. Si prega di utilizzarlo a proprio rischio. Qualsiasi problema o feedback è sempre ben accetto e può essere inviato tramite il repository su GitHub.

