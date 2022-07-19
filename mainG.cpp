#include "grafo.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

/*Definicion de conjunto de palabras.*/ 
set<string> s1={"also", "amazing", "amazon", "android", "another", "app", "apple", "apps", "asia", "asiaclassifiedtoday", "available", "awesome", "baby", "back", "bad", "ballmer", "battery", "beam", "best", "better", "big", "bing", "bit", "blackberry", "blog", "bookcase", "buenas", "business", "buy", "buying", "camera", "ceo", "check", "cloud", "come", "coming", "computer", "cool", "could", "cream", "cualquier", "damn", "data", "day", "days", "deal", "dear", "der", "devices", "dhilipsiva", "di", "digital", "done", "du", "een", "est", "et", "even", "ever", "every", "everyone", "face", "facebook", "fail", "fb", "feature", "features", "finally", "find", "first", "fix", "follow", "followers", "free", "fuck", "funny", "für", "galaxy", "galaxynexus", "game", "gates", "genius", "get", "getting", "give", "go", "going", "good", "goodnight", "google", "googleplus", "got", "great", "gt", "haha", "hate", "hello", "help", "hey", "hours", "ice", "icecreamsandwich", "icloud", "ics", "im", "ios", "ipad", "iphone", "ipod", "itunes", "jajaja", "je", "job", "jobs", "kinect", "know", "lanza", "let", "life", "like", "line", "live", "lol", "look", "looks", "love", "lt", "lucky", "ly", "mac", "made", "make", "makes", "man", "mango", "many", "marketing", "microsoft", "million", "minutes", "mobile", "mommy", "much", "music", "naar", "need", "needs", "net", "network", "never", "new", "news", "next", "nexus", "nexusprime", "nfc", "nice", "night", "nokia", "nuevo", "office", "official", "oficial", "oh", "ok", "omnitouch", "one", "online", "op", "page", "pc", "people", "phone", "phones", "please", "post", "pretty", "put", "real", "really", "release", "right", "rt", "samsung", "sandwich", "say", "says", "screen", "sdk", "search", "see", "send", "seo", "server", "service", "sharepoint", "shit", "shows", "si", "siri", "site", "sitio", "skype", "smartphone", "social", "socialmedia", "software", "start", "steve", "steveballmer", "stevejobs", "still", "stop", "store", "support", "sur", "system", "ta", "take", "teamfollowback", "tech", "technology", "tecnologia", "tell", "thank", "thanks", "think", "time", "today", "tomorrow", "top", "touch", "touchscreen", "twandroid", "tweets", "twitter", "und", "update", "updates", "upgrade", "us", "use", "user", "users", "using", "van", "version", "via", "video", "voor", "vs", "wait", "want", "way", "web", "week", "weekend", "well", "win", "windows", "windowsphone", "work", "working", "world", "would", "wow", "xbox", "xd", "yahoo", "year", "yet", "youtube"};
set<string> s2={"add","age","ah","already","also","amazing","amazon","android","announces","another","anyone","app","apple","apps","aqui","asia","asiaclassifiedtoday","ass","available","away","awesome","azure","baby","back","bad","ballmer","bar","battery","beam","best","better","big","bill","bing","bit","blackberry","blog","bookcase","buenas","builds","business","buy","buying","buzz","camera","cc","ceo","change","check","cloud","come","coming","company","computer","cool","could","cream","cualquier","customer","damn","dans","dat","data","day","days","deal","dear","der","des","design","devices","dhilipsiva","di","die","digital","done","dormir","du","dynamics","ebook","een","email","est","et","even","event","ever","every","everyone","face","facebook","fail","family","fan","fast","fb","feature","features","feel","ff","finally","find","first","fix","follow","followers","free","fuck","fucking","full","funny","future","für","gaga","gain","galaxy","galaxynexus","game","gates","genius","gente","get","getting","give","giving","gmail","go","going","good","goodnight","google","googleplus","got","gplus","great","gt","guess","haha","hand","hate","hell","hello","help","hey","hold","home","hong","hours","hoy","ice","icecream","icecreamsandwich","icloud","ics","ik","im","imessage","improvements","infinite","info","interesting","ios","ipad","iphone","iphones","ipod","issues","itunes","jajaja","je","job","jobs","join","keep","kinect","know","kong","lanza","last","learning","let","life","like","line","linux","little","live","lol","look","looks","lot","love","lt","lucky","ly","mac","macbook","made","make","makes","making","man","management","mango","many","market","marketing","mañana","media","mejor","memories","microsoft","million","minutes","mobile","mommy","motorola","much","music","naar","name","need","needs","neowin","net","network","never","new","news","next","nexus","nexusprime","nfc","nice","night","noches","nokia","nuevo","office","official","oficial","oh","ok","old","omnitouch","one","online","op","page","pampers","pampershelloapps","pas","pc","pdf","people","per","phone","phones","photo","please","post","pour","powered","ppl","pra","pretty","prime","problem","product","products","project","put","qe","read","real","really","recognition","release","released","releases","research","retweets","right","rt","samsung","sandwich","say","says","screen","sdk","search","seconds","see","send","seo","seriously","server","service","services","sharepoint","sharing","shit","shows","si","since","siri","site","sitio","skype","sleep","smartphone","social","socialmedia","socialnetwork","software","sold","something","sometimes","sony","start","steve","steveballmer","stevejobs","still","stop","store","stores","superficie","support","sur","sure","surface","system","ta","tablets","take","teamfollowback","tech","technology","tecnologia","tell","thank","thanks","thing","think","though","time","times","today","tomorrow","tools","top","touch","touchscreen","try","turn","twandroid","tweet","tweets","twitter","two","táctil","und","une","unlock","update","updates","upgrade","us","use","user","users","using","van","ver","version","via","video","voor","vs","wait","waiting","want","war","watching","way","web","week","weekend","welcome","well","win","windows","windowsphone","word","work","working","works","world","would","wow","wtf","xbox","xd","yahoo","yeah","year","years","yet","youtube"};
set<string> s3={"aan", "ab", "able", "absolutely", "acabo", "access", "according", "account", "accounts", "actually", "ad", "add", "addicted", "address", "addthis", "adobe", "ads", "advertising", "adwords", "age", "agora", "agree", "ah", "ahead", "ahora", "ai", "air", "aka", "aki", "allow", "almost", "already", "als", "also", "always", "amazing", "amazon", "ambercole", "amigo", "amp", "analytics", "android", "androidbeam", "andy", "announce", "announced", "announcement", "announces", "annoyed", "another", "answer", "antiguo", "antitrust", "anuncia", "anymore", "anyone", "anything", "anyway", "apart", "aplicaciones", "app", "apparently", "apple", "application", "applications", "applies", "apply", "appreciated", "apps", "appsense", "appstore", "aqui", "area", "around", "article", "asi", "asia", "asiaclassifiedtoday", "ask", "asked", "ass", "att", "attacks", "auf", "augnl", "aujourd", "autopilot", "av", "available", "avec", "avoir", "away", "awesome", "azure", "años", "baby", "back", "backup", "bad", "ballmer", "bar", "based", "battery", "battle", "beam", "beat", "beating", "beautiful", "bed", "begin", "behind", "believe", "bem", "ben", "best", "bestbuy", "beta", "better", "beyond", "bgr", "bi", "bien", "bienvenida", "big", "bij", "bill", "billgates", "billion", "bing", "bit", "bitch", "biz", "black", "blackberry", "blog", "blue", "boa", "body", "bom", "book", "bookcase", "bookmarks", "books", "boring", "bottom", "bought", "bout", "boy", "brand", "brasil", "break", "brilliant", "bring", "brings", "browser", "buen", "buenas", "bueno", "bug", "build", "building", "builds", "built", "bullying", "bunch", "bus", "business", "button", "buy", "buying", "buzz", "bye", "cada", "calendar", "call", "called", "calling", "calls", "came", "camera", "canada", "cant", "capabilities", "card", "care", "carriers", "case", "casi", "caso", "cast", "cause", "cc", "ce", "celebrity", "center", "ceo", "cette", "chance", "change", "changed", "changes", "changing", "charge", "charts", "chat", "che", "cheap", "check", "child", "chrome", "cierto", "circles", "cisco", "citrix", "click", "client", "closer", "cloud", "cnbc", "cnet", "code", "codename", "collaboration", "come", "coming", "comme", "community", "companies", "company", "competition", "compiler", "computer", "conference", "confirms", "congrats", "connect", "connections", "consider", "console", "consumer", "cont", "contact", "contacts", "content", "contract", "control", "convierte", "cool", "cosas", "cost", "could", "couple", "crap", "crash", "crashing", "crazy", "cream", "create", "creating", "creo", "crm", "cross", "ctp", "cualquier", "cuenta", "current", "curso", "customer", "customers", "cuz", "cómo", "dag", "daily", "damn", "dan", "dando", "dank", "dans", "dar", "dark", "dat", "data", "day", "days", "db", "dead", "deal", "dear", "death", "decir", "declarar", "default", "definitely", "delete", "dell", "demo", "den", "der", "des", "design", "desktop", "details", "detik", "deus", "dev", "developer", "developers", "development", "device", "devices", "dhilipsiva", "di", "dia", "dias", "die", "diego", "different", "digital", "direct", "dis", "disappointed", "dispositivos", "dnt", "docs", "done", "dont", "door", "dormir", "download", "drain", "droid", "drop", "dropbox", "drops", "du", "due", "dumb", "dynamics", "día", "early", "earnings", "earth", "easy", "ebook", "eclipsed", "edatpost", "edge", "edu", "education", "een", "eerste", "eingeloggte", "either", "else", "email", "emails", "employees", "encanta", "encore", "encrypting", "encryption", "end", "engadget", "engineer", "enough", "enterprise", "er", "eric", "erp", "error", "est", "et", "etc", "europe", "even", "event", "evento", "ever", "every", "everybody", "everyone", "everything", "everytime", "evil", "ex", "excel", "exchange", "excited", "experience", "explain", "explorer", "eye", "face", "facebook", "facial", "fact", "fail", "failed", "failing", "fait", "falta", "family", "fan", "far", "fast", "fastcompany", "favorite", "fb", "feature", "featured", "features", "feel", "feliz", "fell", "ff", "file", "files", "finally", "finance", "financial", "find", "fine", "firefox", "first", "fix", "fixed", "fixing", "fn", "focus", "folders", "folks", "follow", "followers", "followfriday", "following", "followme", "follownow", "font", "forbes", "forget", "format", "forward", "foto", "found", "foundation", "four", "free", "friend", "friends", "front", "fsf", "fuck", "fucking", "fuckyoumean", "full", "fun", "funny", "future", "für", "gadgets", "gaga", "gain", "galaxy", "galaxynexus", "gallery", "game", "games", "gates", "geeks", "generation", "genius", "gente", "get", "gets", "gettin", "getting", "gingerbread", "girl", "give", "giving", "glad", "global", "globe", "gmail", "gn", "go", "god", "goed", "goes", "goin", "going", "gold", "gon", "gone", "good", "goodnight", "google", "googleapps", "googleplus", "got", "gplus", "gracias", "great", "growth", "gt", "guardian", "guess", "guy", "guys", "haalt", "hace", "hacer", "hack", "hacked", "haha", "hahaha", "half", "hand", "hands", "happened", "happening", "happy", "hard", "hardware", "hashtags", "hate", "hd", "hear", "hell", "hella", "hello", "help", "helps", "hersheytech", "het", "heute", "hey", "high", "history", "hit", "hoes", "hoje", "hold", "holder", "holiday", "holodesk", "home", "hong", "honor", "hope", "hot", "hotmail", "hour", "hours", "hoy", "hp", "htc", "htt", "huge", "hui", "humor", "hyperv", "ibm", "ice", "icecream", "icecreamsandwich", "ich", "ichiro", "icloud", "ics", "ict", "idea", "ie", "ifb", "ii", "ik", "il", "im", "imac", "image", "images", "imessage", "important", "impressed", "impressive", "improvements", "include", "incredible", "india", "infinite", "info", "infographic", "information", "infosys", "innovation", "input", "install", "installed", "instead", "integrated", "interesting", "interface", "internet", "introduces", "introducing", "intune", "intégration", "ios", "ip", "ipad", "ipads", "iphone", "iphones", "ipod", "issue", "issues", "ist", "it", "items", "itunes", "ja", "jail", "jaja", "jajaja", "jajajaja", "japan", "je", "jesus", "jetzt", "job", "jobs", "join", "kan", "ke", "keep", "keeps", "key", "keyboard", "kickoff", "kidding", "kids", "kijk", "kill", "kind", "kinect", "king", "know", "kong", "langsame", "lanza", "laptop", "last", "late", "later", "latest", "launch", "launches", "launching", "lead", "leadership", "learn", "learned", "learning", "least", "leaving", "left", "less", "let", "lets", "life", "light", "like", "likes", "lil", "linda", "line", "lines", "link", "linkedin", "links", "linux", "lion", "list", "listed", "listening", "literally", "little", "live", "living", "llamado", "lmao", "local", "location", "lock", "log", "logged", "lol", "long", "longer", "look", "looking", "looks", "lose", "lost", "lot", "love", "lovers", "loving", "low", "lt", "lucky", "luego", "lunch", "ly", "lync", "mac", "macbook", "made", "mail", "make", "makes", "making", "man", "manage", "management", "manager", "manejar", "mango", "many", "mark", "market", "marketing", "mashable", "mataron", "may", "maybe", "mañana", "med", "media", "medio", "meer", "meghankel", "mejor", "mejores", "memories", "menos", "mention", "mentions", "message", "met", "metro", "mf", "microsoft", "microsoftstores", "middle", "might", "migrating", "mijn", "million", "millones", "min", "mind", "mins", "minutes", "miss", "missed", "missing", "mit", "mobile", "mobileme", "moda", "mode", "model", "moment", "momento", "mommy", "mon", "money", "monopolio", "month", "months", "mooi", "morning", "motorola", "mouse", "mov", "move", "movement", "moving", "mp", "mr", "ms", "msft", "msn", "much", "multiple", "mundo", "music", "must", "mustfollow", "même", "naar", "name", "named", "ne", "neck", "need", "needed", "needs", "nejbye", "neowin", "neowinfeed", "net", "network", "never", "new", "news", "newsstand", "next", "nexus", "nexusprime", "nfc", "nice", "nicht", "niet", "nieuwe", "nigga", "niggas", "night", "noche", "noches", "noite", "nokia", "non", "none", "notes", "nothing", "noticias", "notifications", "nouvelle", "nov", "novell", "november", "noviembre", "novo", "nu", "nueva", "nuevo", "number", "nunca", "nur", "occupy", "offer", "offers", "office", "official", "officially", "oficial", "oficialmente", "often", "oh", "ok", "old", "om", "omg", "omnitouch", "onda", "one", "online", "ook", "oomf", "op", "open", "opens", "operating", "oracle", "order", "others", "outlook", "outside", "pa", "pack", "page", "pages", "paid", "pampers", "pampershelloapps", "panda", "panorama", "pantalla", "paper", "part", "parte", "partner", "partners", "partnership", "party", "pas", "pasa", "paso", "pass", "past", "patent", "pattern", "pay", "paying", "pc", "pdf", "peeler", "people", "per", "perfect", "perfil", "perks", "person", "personal", "personalization", "personas", "peu", "phone", "phones", "photo", "photos", "pic", "picture", "pictures", "piece", "piracy", "pissed", "pittsburgh", "place", "plan", "plans", "platform", "play", "played", "players", "playful", "playing", "please", "pls", "plus", "pockettouch", "pode", "point", "poker", "possibilité", "post", "posted", "posts", "pour", "power", "powered", "powerpoint", "ppl", "pra", "pre", "presenta", "presentation", "presentations", "press", "pretty", "preview", "price", "prime", "principal", "privacy", "private", "pro", "problem", "problems", "process", "product", "productivity", "products", "profile", "program", "project", "promise", "promo", "properly", "proves", "provide", "proyecto", "ps", "public", "publicly", "puede", "puedo", "pues", "pull", "purchase", "push", "put", "putting", "qe", "qu", "quality", "que", "question", "questions", "qui", "quick", "quiero", "raise", "razr", "read", "reader", "ready", "real", "really", "recognition", "reconnaissance", "record", "redes", "register", "release", "released", "releases", "remember", "repeat", "replaced", "report", "reporting", "reports", "request", "research", "researchers", "reservation", "restore", "results", "retail", "retweet", "retweets", "reuters", "reveal", "reveals", "revenue", "review", "revolution", "rianru", "right", "rim", "rolling", "roslyn", "round", "rt", "rules", "rumor", "run", "running", "sabe", "said", "saindo", "sale", "sales", "samsung", "samsunggalaxynexus", "san", "sandwich", "sap", "save", "saw", "say", "saying", "says", "scalability", "school", "science", "scientist", "screen", "sdk", "search", "searches", "second", "seconds", "secure", "security", "see", "seems", "seen", "seguidores", "seguir", "según", "selling", "sells", "send", "sense", "seo", "seriously", "server", "service", "services", "session", "set", "setup", "sex", "share", "sharepoint", "sharing", "shit", "show", "showing", "shows", "si", "side", "siempre", "sign", "sigo", "sigsource", "sigue", "simple", "simply", "since", "siri", "site", "sites", "sitio", "sizes", "skype", "slams", "sleep", "slow", "sm", "small", "smart", "smartphone", "smartphones", "smau", "smh", "smm", "sms", "social", "socialmedia", "socialnetwork", "software", "sold", "solo", "solution", "solutions", "somebody", "someone", "something", "sometimes", "sont", "sony", "soon", "sorry", "sound", "sounds", "source", "space", "spam", "specs", "speech", "speed", "spend", "spigot", "spotted", "sprint", "sql", "sqlserver", "ssl", "stage", "stand", "starring", "start", "started", "starting", "stay", "step", "steps", "steve", "steveballmer", "stevejobs", "still", "stop", "store", "stores", "story", "strategy", "stream", "street", "stuck", "student", "study", "stuff", "stupid", "success", "suche", "sucks", "suit", "summit", "super", "superficie", "support", "sur", "sure", "surface", "surprised", "sweet", "sympa", "sync", "system", "systemcenter", "sé", "ta", "tablet", "tablets", "take", "takes", "taking", "talk", "talking", "tan", "taste", "tcn", "team", "teamfollowback", "tech", "techedafrica", "technical", "technology", "teclado", "tecnologia", "tecnología", "telefono", "telegraph", "tell", "teléfono", "terrible", "test", "testing", "tests", "texas", "text", "texts", "tfb", "thank", "thanks", "thats", "thing", "things", "think", "thinking", "thinks", "tho", "though", "thought", "thoughts", "three", "thx", "tiempo", "til", "time", "timeline", "times", "tip", "tips", "tired", "tod", "today", "together", "told", "tomorrow", "tonight", "took", "tool", "tools", "top", "total", "totally", "touch", "touchscreen", "tout", "trabajar", "traffic", "training", "trending", "tres", "tribute", "tried", "trip", "trouble", "try", "trying", "très", "tt", "tudo", "tumblr", "turn", "turned", "turns", "tv", "twandroid", "tweeps", "tweet", "tweeted", "tweeting", "tweets", "twidroyd", "twitter", "twittertime", "two", "type", "táctil", "ugh", "ui", "uit", "uk", "umber", "uncategorized", "und", "une", "unlock", "unlocked", "unveil", "unveiled", "unveils", "unwrapping", "update", "updated", "updates", "updating", "upgrade", "upgrading", "ups", "ur", "us", "usa", "usage", "usar", "use", "used", "useful", "user", "users", "using", "usuarios", "va", "vai", "van", "vc", "vende", "venturebeat", "ver", "verizon", "vers", "verschlüsselt", "version", "vez", "vi", "via", "vida", "video", "views", "virtual", "vistazo", "visual", "vmware", "vmworld", "vocale", "voice", "voir", "volgende", "von", "voor", "vou", "vous", "voy", "vs", "vía", "wait", "waiting", "wall", "wallet", "wan", "want", "wants", "war", "wars", "wasting", "wat", "watch", "watching", "way", "ways", "web", "webcast", "webgl", "webinar", "website", "week", "weekend", "weer", "wel", "welcome", "well", "went", "white", "whymicrosoft", "widgets", "wie", "wikileaks", "win", "windows", "windowsphone", "winning", "wireless", "wish", "wit", "without", "women", "wonder", "word", "work", "working", "works", "world", "worldwide", "worse", "worst", "worth", "would", "wow", "wrong", "wspsandiego", "wspwest", "wtf", "www", "xbox", "xd", "yahoo", "yeah", "year", "years", "yes", "yesterday", "yet", "yonopienso", "youtube", "yvandavid", "zeer", "zijn", "zo", "zoek", "zum", "zune", "être", "über", "версию", "как", "на", "новую", "операционной", "представили", "системы", "من", "نظام", "ショウケース", "記録", "銀座"};
/*-----------------------------------*/

/*Inicializacion de funcion que lee una linea, elimina puntuacion, 
pasa a minuscula y retorna las palabras en el conjunto.*/
void foo(string line, vector<string> &v, int nconj);  //EDITADO
/*-----------------------------------*/

/*Inicializacion de la funcion que lee el documento original*/  //EDITADO
vector< vector<string> > lectura(int nlinea, string archivo, int nconj);
/*-----------------------------------*/

/*Se retornan las palabras que estan en el conjunto y la linea 
leida mediante un vector. Usar el ciclo para recorrerlas.*/
int main(){
    string archivo="dataset-proyecto";
    int nlinea, nconj;
    
    //cout<<"Ingrese el nombre del archivo (sin .csv) y el número de lineas a leer"<<endl;
    cout<<"Numero de lineas (máx 5113) y conjunto a usar (1,2,3) ";
    cin>>nlinea>>nconj;
    
    vector< vector<string> > v=lectura(nlinea, archivo,nconj);


//--------------------GUARDAR EN ESTRUCTURAS----------------------------------//


    Grafo G;
    for(int i=0; i<nlinea; i++){
        string TweetID = v[i][0];           
        string TweetDate= v[i][1];
        vector<string> TweetText; 
        for(int j=2; j<v[i].size()-1; j++)TweetText.push_back(v[i][j]);
        string UserId = v[i][v[i].size()-1];
        G.insertar(TweetID,TweetDate,TweetText, UserId);
    }
 
   
    //Consulta sobre estadisticas
    G.numVertices('M');
    G.numVertices('U');
    G.numVertices('F');
    G.numVertices('P');
    G.numAristas();
    G.menorGrado(); 
    G.mayorGrado(); 


    //Consultas sobre los datos
    cout<<"La fecha con mas tweets es: ";
    G.fechaMasTweets();

    cout<<"El usuario con mas tweets es ";
    G.usuarioMasTweets();

    G.palabraMasLarga();
 
    string palabra;
    cout<<"Ingrese palabra para buscar: ";
    cin >> palabra;
    cout<<endl;

    cout<<"Usuarios que han dicho la palabra "<<palabra<<": "<<endl;

    G.usuariosPalabra(palabra);
    

    cout<<"Fechas en las que se ha dicho la palabra "<<palabra<<": "<<endl;

    G.fechasPalabra(palabra);

    

}


/*Definicion de funcion que realiza el preprocesamiento
y analisis de pertenencia de las palabras en el conjunto*/
void foo(string line, vector<string> &v, int nconj){    //Tiempo de la función O(m)
    string cadena;                  //Definición de string O(1)
    
    for (int i=0; i<line.size(); i++){
        if (ispunct(line[i])) line[i] = ' ';
        line[i]=tolower(line[i]);
    }

    set<string> s;

    if(nconj==1) s=s1;
    else if(nconj==2) s=s2;
    else if(nconj==3) s=s3;

    /*Se utiliza istringstream para el paso del string a un formato de
    lectura que permite aplicar getline para su lectura con el delimitador
    deseado, en este caso, un espacio. Información obtenida de:
    https://www.cplusplus.com/reference/istream/istream/getline/ */
    
    istringstream Separador(line);  //Paso de string a cadena de string se
                                    //presume O(m), donde m largo de la cadena.
    
    while(getline(Separador, cadena, ' ')){         //Ciclo for O(1)
        if(s.count(cadena)!=0) v.push_back(cadena); //Añadir elemento al vector O(1)
    }
    return;   //Retornar vector O(1)
}


/*Funcion que lee linea por linea y retorna un vector de vector de string*/
vector<vector<string> > lectura(int nlinea, string archivo, int nconj){
	vector<vector<string> > row;
	string line, word, word2;
	int cont=0;
	fstream file(archivo+".csv", ios::in);
	
	if(!file.is_open()){
		cout<<"Archivo no encontrado\n";
		return row;
	}
	getline(file, line);

	while((getline(file, line)) && (cont<nlinea)){
		stringstream str(line);
        vector<string> vec;
		
        getline(str, word, '"');
        getline(str, word, '"');
        vec.push_back(word);
        

        getline(str, word, '"');
        getline(str, word, '"');
        vec.push_back(word);


        getline(str, word, '"');
        getline(str, word, '"');
        foo(word, vec,nconj);
        getline(str, word, '"');

        while(word.size()!=1){
            if(word.size()==0){
                getline(str, word, '"');
                foo(word, vec,nconj);
                getline(str, word, '"');
            }else{
                foo(word, vec,nconj);
                getline(str, word, '"');
            }
        }

        if(word.size()==1){
            getline(str, word, '"');
            if(word.size()==1){
                getline(str, word, '"');
                vec.push_back(word);
            }else
                vec.push_back(word);
        }

        row.push_back(vec);
		cont++;
	}
	file.close();
	return row;
}

