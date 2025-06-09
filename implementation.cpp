#include "events.h" // includes the events header

set<User*> allUsers; // responsible for maintaining all registered user accounts
set<Event*> allEvents; // responsible for maintaining all events

//////////////////////////   Menu   //////////////////////////

// the starting setup function that is called in main
void Menu::setup() {
    loadUsersData();
    loadEventsData();
    cout << "=========================" << endl;
    cout << "=========WELCOME=========" << endl;
    cout << "=========================" << endl;

    start_menu();
}

// a function for the user to either login or sign up
void Menu::start_menu(){
    int choice;
    while (true){ // loops until a valid input is entered
        cout << "\nPlease choose one of these options:" << endl;
        cout << "1) Login" << endl;
        cout << "2) Signup" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter a number: ";
        cin >> choice; // user enters choice

        // handles non-integer input
        if (cin.fail()) { // checks if any previous cin operation failed
            cin.clear();// resets the error flags on cin stream
            // discards all characters in input buffer with the max number in mind until new line is encountered
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue; // skips rest of loop iteration, returns to menu
        }

        switch (choice) {
            case 1:
                main_menu(login()); // calls for the main_menu function with login function as a parameter
                break;
            case 2:
                signup(); // signs up user
                break;
            case 3: // saves events & user info into a file and exits
                saveEventsToFile();
                saveUsersToFile();
                exit(0);
            default:
                cout << "Invalid choice, please choose 1, 2 or 3." << endl; // error message
        }
    }
}

// a function that displays and handles the main user menu after successful login
void Menu::main_menu(User* user){ // parameter : a pointer to the logged-in User
    if (user == nullptr) return; // a safety check for null user
    int choice;
    while (true) {
        cout << "\nPlease choose one of these options:" << endl;
        cout << "1) Schedule Meeting" << endl;
        cout << "2) Register for a Meeting" << endl;
        cout << "3) Search for a Meeting" << endl;
        cout << "4) Postpone Meeting" << endl;
        cout << "5) Cancel Meeting" << endl;
        cout << "6) Open Calendar for user" << endl;
        cout << "7) Give feedback" << endl;
        cout << "8) Review previous feedbacks"<< endl;
        cout << "9) Sign out"<<endl;
        cout << "Enter a number: ";
        cin >> choice; // user picks an option

        // handles non-integer input
        if (cin.fail()) { // checks if any previous cin operation failed
            cin.clear();// resets the error flags on cin stream
            // discards all characters in input buffer with the max number in mind until new line is encountered
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue; // skips rest of loop iteration, returns to menu
        }

        switch (choice) {
            case 1:
                user->schedule_event(); // schedules a new event
                break; // Continue the loop to let the user choose again
            case 2:
                user->register_event(); // registers in an event
                break;
            case 3:
                search_menu(); // search for an event
                break;
            case 4:
                user->postpone_meeting(); // postpone an event
                break;
            case 5:
                user->cancel_meeting(); // cancel an event
                break;
            case 6:
                user->viewUserEvents(); // view scheduled + registered events
                break;
            case 7:
                Menu::feedback_menu(user);  // submit feedback
                break;
            case 8:
                Feedback::review_feedbacks(user); // view feedback history
                break;
            case 9:
                start_menu();  // sign out and return to the start menu
                return; // exit the loop and the main_menu function
            default:
                cout << "Invalid choice, please choose a number." << endl; // error message
        }
    }
}

// a function to help a user search for an event
void Menu::search_menu(){
    int search_choice;
    cout << "\nPlease choose one of these options:" << endl;
    cout << "1) Search by Event name" << endl;
    cout << "2) Search by Event date" << endl;
    cout << "3) Search by Event type" << endl;
    cout << "Enter a number: ";
    cin >> search_choice;
    switch(search_choice){
        case 1:
            search_by_name(); // searches for event by name
            break;
        case 2:
            search_by_date(); // searches for event by date
            break;
        case 3:
            search_by_type(); // searches for event by type
            break;
        default:
            cout << "Invalid choice, please choose 1, 2 or 3." << endl; // error message
            break;
    }
}

// a function that searches events by type
void search_by_type(){
    set<Event*> matchedEvents; // stores found events

    cout << "\nPlease choose the type of the event: (enter 0 to exit)" << endl;
    cout << "1) Conference" << endl;
    cout << "2) Webinar" << endl;
    cout << "3) Workshop" << endl;
    cout << "Enter a number: ";
    int searched_type;
    string searched_typeSTR; // a string representation of the chosen type
    while(true){ // loops until it gets a valid input
        if(!(cin >> searched_type)){ // checks if input failed (non-integer input)
            cin.clear(); // clear any error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any invalid input
            cout << "Invalid choice, choose (1-3): ";
            continue;
        }
        // handles the exit condition
        else if(searched_type == 0){
            cout << "Exited searching!" << endl;
            loadingAnimation(3); // shows the loading animation for 3 seconds
            return;
        }
        // validates the range
        else if(searched_type < 1 || searched_type > 3){
            cout << "Invalid choice, choose (1-3): ";
        }
        else break; // a valid input is received -> exit loop
    }

    // converts a numeric choice to string representation
    switch(searched_type){
    case 1:
        searched_typeSTR = "Conference";
        break;
    case 2:
        searched_typeSTR = "Webinar";
        break;
    case 3:
        searched_typeSTR = "Workshop";
        break;
    }

    // searches through all events finding a match
    for(Event* event : allEvents){
        if(searched_typeSTR == event->getType()){
            matchedEvents.insert(event); // add matching event to the results set
        }
    }

    // handles search results
    if(matchedEvents.empty()){
        cout << "No results found!" << endl;
        loadingAnimation(3);
    }else{
        cout << endl;
        printMultiset(matchedEvents); // displays all found events
    }

}

// a function that searches events by date
void search_by_date(){
    set<Event*> matchedEvents; // stores found events

    cout << "Enter event date (YYYY-MM-DD): (enter '0' to exit)" << endl;
    string searched_event_date;
    // reads the input with whitespace handling (>> ws skips leading whitespace)
    getline(cin >> ws, searched_event_date);

    // handles exit condition
    if(searched_event_date == "0"){
        cout << "Exited searching!" << endl;
        loadingAnimation(3);
        return; // exits the function early
    }

    // searches through all events for date matches
    for(Event* event : allEvents){
        if(searched_event_date == event->getDate()){
            matchedEvents.insert(event); // adds the matching event to results
        }
    }

    // displays search results
    if(matchedEvents.empty()){
        cout << "No results found!" << endl;
        loadingAnimation(3);
    }else{
        cout << endl;
        printMultiset(matchedEvents); // prints all matching events
    }
}

// a function that searches events by name
void search_by_name(){
    set<Event*> matchedEvents; // stores found events

    cout << "Enter event name: (enter '0' to exit)" << endl;
    string searched_event_name;
    // it reads the user's input with leading whitespace removal
    // where '>> ws' discards any whitespace before the actual input
    getline(cin >> ws, searched_event_name);

    // handles the exit condition if the user enters '0'
    if(searched_event_name == "0"){
        cout << "Exited searching!" << endl;
        loadingAnimation(3);
        return; // exits the function immediately
    }

    // performs a linear search through all events
    for(Event* event : allEvents){
        // a case-sensitive exact name comparison
        if(searched_event_name == event->getName()){
            matchedEvents.insert(event); // stores matching event pointer
        }
    }

    // handles and displays search results
    if(matchedEvents.empty()){
        cout << "No results found!" << endl;
        loadingAnimation(3);
    }else{
        cout << endl;
        printMultiset(matchedEvents); // displays all matching events
    }
}

// a function that handles the feedback submission process for a logged-in user
void Menu::feedback_menu(User* user) {
    // loads all events associated with this user
    set<Event*> registeredEvents = user->get_registered_events();

    // checks if the user has any registered events
    if (registeredEvents.empty()) {
        cout << "\nNo events found to give feedback on!" << endl;
        loadingAnimation(3);
        return; // exits if no events available
    }

    // lists all available events for the user to choose from
    cout << endl;
    cout << "Select an event to give feedback on:" << endl;
    int index = 1;
    vector<Event*> eventList; // this stores events for easy index access

    // prints each event with its details
    for (Event* e : registeredEvents) {
        cout << index++ << ") " << e->getName() << " on " << e->getDate() << " at " << e->getTime() << endl;
        eventList.push_back(e); // add to the vector
    }

    // asks the user to select an event by number
    int choice;
    cout << "Enter event number: ";
    cin >> choice;
    cout << endl;

    // checks if the user selection is valid
    if (choice < 1 || static_cast<size_t>(choice) > eventList.size()) {
        cout << "Invalid choice!" << endl;
        return; // exits on invalid input
    }

    // gets the selected event
    Event* selectedEvent = eventList[choice - 1];

    // extracts event details
    string eventTitle = selectedEvent->getName();
    string eventDate = selectedEvent->getDate();
    string eventType = selectedEvent->getType();
    string creator = selectedEvent->getCreator()->getUsername();

    // creates a feedback object
    Feedback fb(user->getUsername(), eventTitle, eventType, eventDate);

    // attaches the event creator as an observer
    User* creatorUser = nullptr;
    for (const User* user : allUsers) {
        if (user->getUsername() == creator) {
            creatorUser = const_cast<User*>(user); // removes const for observer attachment
            fb.attach(creatorUser); // creator will receive a notification
            break;
        }
    }

    // defines a list of feedback aspects
    vector<string> aspects = {"Content", "Delivery", "Relevance", "Duration"};

    // collects & processes feedback
    if (fb.collectFeedbackInteractive(aspects)) {
        fb.display(true); // show notice if an event is in the future
        fb.saveToFile();
        fb.notify(); // notify observers (which now includes creatorUser)
    } else {
        cout << "Feedback not collected because the event has not been launched yet." << endl; // output message
    }
}

//////////////////////////   User   //////////////////////////

User::User(){} // default constructor
// parameterised constructor
User::User(string u, string p, string e, string a): username(u), password(p), email(e), affiliation(a){}

void User::setUsername(string u) { username = u; } // sets the username
string User::getUsername() const { return username; } // returns the username

void User::setPassword(string p) { password = p; } // sets password
string User::getPassword() const { return password; } // returns password

void User::setAffiliation(string a){ affiliation = a; } // sets the organizational affiliation
string User::getAffiliation() const{ return affiliation; } // returns the organizational affiliation

void User::setEmail(string e){ email = e; } // sets the email address
string User::getEmail() const{ return email; } // returns email address

// the observer pattern implementation which handles the event's notifications
void User::update(const string& eventName, const string& message) {
    cout << "Notification for " << username << ": " << message << " for event: " << eventName << endl;
}

// the function allows a user to create & schedule a new event
void User::schedule_event(){
    int choice;
    cout << "\nPlease choose the type of the event:" << endl;
    cout << "1) Conference" << endl;
    cout << "2) Webinar" << endl;
    cout << "3) Workshop" << endl;
    cout << "4) Exit" << endl;
    cout << "Enter a number: ";

    while(true){
        if(!(cin >> choice)){ // handles a non-integer input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        else if(choice < 1 || choice > 4){ // handles out-of-range input
            cout << "Invalid input, Please enter a number (1-4): ";
        }
        else break;  // a valid input received
    }

    // creates an event based on the user's selection
    Event* event = nullptr; // a pointer to hold the new event
    // factory patterns being applied
    switch (choice) {
        case 1:
            event = Event::eventBuilder(Conference_, this);
            break;
        case 2:
            event = Event::eventBuilder(Webinar_, this);
            break;
        case 3:
            event = Event::eventBuilder(Workshop_, this);
            break;
        case 4:
            return; // aborts event creation
        default:
            return;
    }

    // if the event is created successfully
    if (event) {
        allEvents.insert(event); // adds to the global event collection
    }
    cout << "Event scheduled successfully!" << endl;
    loadingAnimation(3);
}

// retrieves all the events created by this user from the global allEvents set
set<Event*> User::get_scheduled_events() {
    set<Event*> userEvents; // this will store events created by this user
    // loops through all events
    for(Event* event : allEvents){
        // compares the creator's username with current user's username
        if(username == event->getCreator()->getUsername())
            userEvents.insert(event); // adds to the result set if creator matches
    }
    return userEvents; // returns the set of owned events (which could be empty)
}

// this function handles the event registration process for the current user
void User::register_event(){
    vector <Event*> events; // collects the events the user can register for
    for(Event* event : allEvents){
        if (username == event->getCreator()->getUsername()) continue; // this skips self-created events
        events.push_back(event); // adds to available events list
    }
    // checks if any events are available
    if (events.empty()){
        cout << "\nNo events available for registration." << endl;
        loadingAnimation(3);
        return; // exits if there is no events
    }

    // displays the available events with details
    cout << "\nAvailable events:" << endl;
    for(int i=0 ; i<events.size() ; i++){
        cout << "----------------------------" << endl;
        cout << i+1 << ")\n";
        events[i]->displayDetails(); // this shows the full event's info
        cout << endl;
    }

    // this gets the user's event selection
    cout << "Choose an event to register (1-" << events.size() << ") (enter 0 to exit): ";
    int choice;

    while(true){
        if(!(cin >> choice)){ // this handles non-numeric inputs
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice, choose (1-" << events.size() << "): ";
            continue;
        }
        else if(choice == 0){ // the exit condition
            cout << "Exited registration" << endl;
            return;
        }
        else if(choice < 1 || choice > events.size()){ // this is a range check
            cout << "Invalid choice, choose (1-" << events.size() << "): ";
        }
        else if(isRegistered(events[choice - 1])){ // this is a duplicate registration check
            cout << "You've already registered for this event!" << endl;
            cout << "Choose another event: " << endl;
        }
        else break; // a valid selection
    }

    // this processes registration
    Event* selectedEvent = events[choice - 1]; // gets the selected event
    if (!selectedEvent->addRegistrar(this)) { // an attempt to register
        cout << "Sorry, this event is already full!" << endl;
        loadingAnimation(3);
    } else {
        cout << "\nYou've registered successfully!" << endl;
        selectedEvent->attach(this); // subscribes to event notifications
        loadingAnimation(3);
    }
}

// this function checks if the current user is registered for a specific event
bool User::isRegistered(Event* event){
    // this gets all users registered for the given event
    set<User*> eventRegistrars = event->getRegistrars();
    // checks if the current user (this) exists in the event's registrars set
    // then find() returns the end() iterator if element is not found
    return(eventRegistrars.find(this) != eventRegistrars.end());
}

// this function gets all the events the current user has registered for
set<Event*> User::get_registered_events() {
    set<Event*> RegisteredEvents; // this will store the events the user is registered for
    // check each event
    for(Event* event : allEvents){
        // gets all users registered for this event
        set<User*> eventRegistrars = event->getRegistrars();
        // check if the current user (this) is in the registrars set
        auto it = (eventRegistrars).find(this);
        // if its found, add the event to results
        if(it != eventRegistrars.end()){
            RegisteredEvents.insert(event);
        }
    }
    return RegisteredEvents; // returns the set of registered events (which could be empty)
}

// this function displays all the events associated with the user (both created + attended)
void User::viewUserEvents(){
    // gets the events the user has created
    set<Event*> ScheduledEvents = get_scheduled_events();
    // gets the events the user has registered for
    set<Event*> RegisteredEvents = get_registered_events();

    // displays the scheduled/created events section
    cout << "\nScheduled ";
    if(ScheduledEvents.empty())
        cout << "Meetings:\n-----------------------------\nYou have no scheduled meetings." << endl;
    else
        printMultiset(ScheduledEvents); // shows all created events

    // displays the registered/attended events section
    cout << "\nRegistered ";
    if(RegisteredEvents.empty())
        cout << "Meetings:\n-----------------------------\nYou have no registered meetings." << endl;
    else
        printMultiset(RegisteredEvents); // shows all registered events
    loadingAnimation(3);
}

// this function allows the user to postpone an event
void User::postpone_meeting() {
    // gets all the events the user has scheduled/created
    set<Event*> userEventsSet = get_scheduled_events();
    vector<Event*> userEvents; // this converts to vector for indexed access
    // copy events from set to vector
    for(Event* event : userEventsSet){
        userEvents.push_back(event);
    }

    // check if the user has any events to postpone
    if (userEvents.empty()){
        cout << "\nYou haven't scheduled any events!" << endl;
        loadingAnimation(3);
        return;
    }

    // this displays the list of the user's events with details
    cout << "\nYour events:" << endl;
    for(int i=0 ; i<userEvents.size() ; i++){
        cout << "----------------------------" << endl;
        cout << i+1 << ")\n";
        userEvents[i]->displayDetails(); // this shows the event information
        cout << endl;
    }

    // this gets the new date and time for postponement
    string newDate, newTime;
    cout << "Choose the event you want to postpone (1-" << userEvents.size() << ") (enter 0 to cancel): ";
    int choice;
    while (true) {
        // this handles non-numeric input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number (0 to cancel): ";
            continue;
        }
        if (choice == 0) { // the cancel condition
            cout << "Postponement canceled.\n";
            loadingAnimation(3);
            return;
        }
        if (choice < 1 || choice > userEvents.size()) { // the range check
            cout << "Invalid choice, choose (1-" << userEvents.size() << "): ";
            continue;
        }
        break;
    }

    // this clears the input buffer before reading new date/time
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Event* selectedEvent = userEvents[choice - 1]; // gets the selected event

    cout << "New date (YYYY-MM-DD): ";
    getline(cin, newDate);
    while((newDate[4] != '-') || (newDate[7] != '-'))  { // a basic format check
        cout << "Wrong format!" << endl << "Enter date (YYYY-MM-DD): ";
        getline(cin, newDate);
    }
    selectedEvent->setDate(newDate); // updates the event date

    cout << "New time (HH:MM): ";
    getline(cin, newTime);
    while(newTime[2] != ':') { // basic format check
    cout << "Wrong format!" << endl << "Enter time (HH:MM): ";
    getline(cin, newTime);
    }
    selectedEvent->setTime(newTime); // updates the event time
    selectedEvent->notify(Event_postponement); // notifies all observers about the postponement

    cout << "Event postponed successfully!\n";

    loadingAnimation(3);
}

// this function allows the user to cancel an event
void User::cancel_meeting() {
    // this gets all the vents the user has created
    set<Event*> userEventsSet = get_scheduled_events();
    vector<Event*> userEvents; // this converts to a vector for indexed selection
    // copies events from set to vector
    for(Event* event : userEventsSet){
        userEvents.push_back(event);
    }

    // this checks if a user has any events to cancel
    if (userEvents.empty()){
        cout << "\nYou haven't scheduled any events!" << endl;
        loadingAnimation(3);
        return;
    }

    // this displays the list of user's events with details
    cout << "\nYour events:" << endl;
    for(int i=0 ; i<userEvents.size() ; i++){
        cout << "----------------------------" << endl;
        cout << i+1 << ")\n";
        userEvents[i]->displayDetails(); // shows the complete event info
        cout << endl;
    }

    string eventName, line;
    cout << "Choose the event you want to cancel (1-" << userEvents.size() << ") (or type 'exit' to cancel): ";
    getline(cin >> ws, eventName); // read the input with whitespace handling
    int choice = stoi(eventName);
    while(true){
        // handles the exit condition first
        if (eventName == "exit") {
            cout << "Exited cancellation.\n";
            loadingAnimation(3);
            return;  // Immediately exit the function
        }
        // converts and validates selection
        else if(choice < 1 || choice > userEvents.size()){
            cout << "Invalid choice, choose (1-" << userEvents.size() << "): ";
        }
        else break;
    }

    // processes cancellation
    Event* selectedEvent = userEvents[choice - 1]; // gets the selected event
    allEvents.erase(selectedEvent); // removes it from global event list
    cout << "Event canceled successfully!\n";
    // then notifies all observers about cancellation
    selectedEvent->notify(Event_cancellation);
    // unsubscribes the user from event notifications
    selectedEvent->detach(this);
    loadingAnimation(3);
}

///////////////////////////   Event   /////////////////////////

Event::Event(){} // default constructor
Event::Event(string n, User* creator, string desc, string p, string d, string t, int c, int f)
    : event_name(std::move(n)), creator_user(creator), description(desc), platform(p), date(d), time(t), capacity(c), full(f) {
    creator_name = creator ? creator->getUsername() : ""; // a parameterised constructor
}

//Implementation of getter functions
string Event::getName() const { return event_name; }
User* Event::getCreator() const { return creator_user;}
string Event::getDescription() const { return description; }
string Event::getDate() const { return date; }
string Event::getTime() const { return time; }
string Event::getPlatform() const { return platform; }
int Event::getCapacity() const { return capacity; }
set<User*> Event::getRegistrars(){ return registrars; }


// updates the event date & time
void Event::setDate(string newDate){ date = newDate; }
void Event::setTime(string newTime){ time = newTime; }

// adds a user to the event's registrar list if capacity allows
bool Event::addRegistrar(User* user){
    if (isFull()) return false; // checks capacity
    registrars.insert(user);  // adds the user to the set
    // updates the full status if the capacity is reached
    if(registrars.size() >= capacity)
        full = 1;
    return true;
}

// this checks if the event has reached maximum capacity
bool Event::isFull(){
    return full;
}

// a factory method which creates a specific event subclass instances based on type
Event *Event::eventBuilder(const eventType Type, User *creator) {
    if (Type == Conference_) {
        return Conference::create_event(creator); // creates a conference instance
    }
    else if (Type == Webinar_) {
        return Webinar::create_event(creator); // creates a webinar instance
    }
    else if (Type == Workshop_) {
        return Workshop::create_event(creator); // creates a workshop instance
    }
    else return nullptr; // invalid type was provided
}

// this function adds an observer to receive event notifications
void Event::attach(Observer* observer) {
    observers_.push_back(observer);
}

// this function removes an observer from notification list
void Event::detach(Observer* observer) {
    observers_.erase(remove(observers_.begin(), observers_.end(), observer), observers_.end());
}

// this function notifies all observers about event changes
void Event::notify(const notificationType type) {
    switch (type) {
        case 0: // notifies about date changes
            for (Observer* observer : observers_) {
                observer->update(this->getName(), "Date changed to " + this->getDate());
            }
            break;
        case 1: // notifies about event cancellation
            for (Observer* observer : observers_) {
                observer->update(this->getName(), "Canceled");
            }
            break;
        default:
            return;
    }
}

////////////////////////   Conference   ////////////////////////////

Conference::Conference(){} // default constructor
Conference::Conference(string n, User* creator, string desc, string p, string d, string t, int c, int dur)
    : Event(n, creator, desc, p, d, t, c, 0), duration(dur) {} // parameterised constructor

// getter functions for event type and duration
string Conference::getType() const{ return "Conference";}
int Conference::getDuration() const{ return duration;}

// an interactive Conference event creation function
Event* Conference::create_event(User* creator){
    // temp variables for user input
    string name, desc, platform, date, time;
    int capacity, duration;

    cin.ignore(); // clears the input buffer
    // these collect the event's details
    cout << "Enter event name: ";
    getline(cin, name);
    cout << "Enter description: ";
    getline(cin, desc);
    cout << "Enter platform: ";
    getline(cin, platform);
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);
    while((date[4] != '-') || (date[7] != '-'))  { // format check
        cout << "Wrong format!" << endl << "Enter date (YYYY-MM-DD): ";
        getline(cin, date);
    }
    cout << "Enter time (HH:MM): ";
    getline(cin, time);
    while(time[2] != ':') { // format check
        cout << "Wrong format!" << endl << "Enter time (HH:MM): ";
        getline(cin, time);
    }
    while (true) {
        cout << "Enter capacity: ";
        cin >> capacity;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        }
        else break;
    }
    while (true) {
        cout << "Enter Duration (In days): ";
        cin >> duration;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        }
        else break;
    }

    // creates + returns a new Conference object
    Conference* conference = new Conference(name, creator, desc, platform, date, time, capacity, duration);
    return conference;
}

// a function to display all the event's details
void Conference::displayDetails() const {
    cout << "Event: " << getName() << " (" << getType() << ")" << endl;
    cout << "Creator: " << (getCreator() ? getCreator()->getUsername() : "Unknown") << endl;
    cout << "Date: " << getDate() << " at " << getTime() << endl;
    cout << "Platform: " << getPlatform() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Capacity: " << getCapacity() << endl;
    cout << "Duration: " << getDuration() << " days" << endl;
}

// a function to save the conference's info into a file
void Conference::saveToFile(ofstream& file){ // append mode
    // writes down core event attributes
    file << getType() << "|"
        << creator_name << "|"
        << event_name << "|"
        << description << "|"
        << date << "|"
        << time << "|"
        << platform << "|"
        << capacity << "|"
        << duration << "|";
    // writes down all registrant usernames
    for(User* registrar : registrars){
        file << registrar->getUsername() << "|";
    }
    file << endl; // the end
}

// a function that creates a Conference object by loading info from a file
Event* Conference::loadFromFile(const string& line){
    stringstream ss(line);
    string creatorName, name, desc, date, time, platform, capacityStr, durationStr, type, registrar;
    // go through the core event attributes from the string
    getline(ss, type, '|');
    getline(ss, creatorName, '|');
    getline(ss, name, '|');
    getline(ss, desc, '|');
    getline(ss, date, '|');
    getline(ss, time, '|');
    getline(ss, platform, '|');
    getline(ss, capacityStr, '|');
    getline(ss, durationStr, '|');

    // converts the numeric values
    int capacity = stoi(capacityStr);
    int duration = stoi(durationStr);

    // finds the creator User object from global list
    User* creator = nullptr;
    for(User* user : allUsers){
        if(user->getUsername() == creatorName){
            creator = user;
            break;
        }
    }

    // this creates a new Conference instance
    Conference* conference = new Conference(name, creator, desc, platform, date, time, capacity, duration);

    // processes all registrants listed after the main attributes
    while(getline(ss, registrar, '|')){
        // find each registrant in global user list
        for(User* user : allUsers){
            if(registrar == user->getUsername())
                conference->addRegistrar(user); // registers user
        }
    }
    return conference;
}

/////////////////////////   Webinar   ///////////////////////////

Webinar::Webinar(){} // a default constructor
Webinar::Webinar(string n, User* creator, string desc, string p, string d, string t, int c, string h)
    : Event(n, creator, desc, p, d, t, c, 0), host(h) {} // a parameterised constructor

// getter functions for the type and host
string Webinar::getType() const{ return "Webinar";}
string Webinar::getHost() const{ return host;}

// a function to display the webinar's details
void Webinar::displayDetails() const {
    cout << "Event: " << getName() << " (" << getType() << ")" << endl;
    cout << "Creator: " << (getCreator() ? getCreator()->getUsername() : "Unknown") << endl;
    cout << "Date: " << getDate() << " at " << getTime() << endl;
    cout << "Platform: " << getPlatform() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Capacity: " << getCapacity() << endl;
    cout << "Host: " << getHost() << endl;
}

// a static factory method implementation which is an interactive Webinar event creation function
Event* Webinar::create_event(User* creator){
    // Temp variables for user input
    string name, desc, platform, date, time, host;
    int capacity;
    cin.ignore(); // clears the input buffer before reading strings
    // collects the webinar's info
    cout << "Enter event name: ";
    getline(cin, name);
    cout << "Enter description: ";
    getline(cin, desc);
    cout << "Enter platform: ";
    getline(cin, platform);
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);
    while((date[4] != '-') || (date[7] != '-'))  { // format check
        cout << "Wrong format!" << endl << "Enter date (YYYY-MM-DD): ";
        getline(cin, date);
    }
    cout << "Enter time (HH:MM): ";
    getline(cin, time);
    while(time[2] != ':') { // format check
        cout << "Wrong format!" << endl << "Enter time (HH:MM): ";
        getline(cin, time);
    }
    while (true) {
        cout << "Enter capacity: ";
        cin >> capacity;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        }
        else break;
    }
    cin.ignore();
    cout << "Enter Host: ";
    getline(cin, host);

    // creates and returns a new Webinar object
    Webinar* webinar = new Webinar(name, creator, desc, platform, date, time, capacity, host);
    return webinar;
}

// a function that saves collected info into a file
void Webinar::saveToFile(ofstream& file){ // append mode
    // writes down all the info
    file << getType() << "|"
        << creator_name << "|"
        << event_name << "|"
        << description << "|"
        << date << "|"
        << time << "|"
        << platform << "|"
        << capacity << "|"
        << host << "|";
    // writes down all registrant usernames
    for(User* registrar : registrars){
        file << registrar->getUsername() << "|";
    }
    file << endl;
}

// a function that creates a webinar object by loading info from a file
Event* Webinar::loadFromFile(const string& line){
    stringstream ss(line);
    string creatorName, name, desc, date, time, platform, capacityStr, host, type, registrar;
    // go through the core event attributes from the string
    getline(ss, type, '|');
    getline(ss, creatorName, '|');
    getline(ss, name, '|');
    getline(ss, desc, '|');
    getline(ss, date, '|');
    getline(ss, time, '|');
    getline(ss, platform, '|');
    getline(ss, capacityStr, '|');
    getline(ss, host, '|');

    // converts the numeric values
    int capacity = stoi(capacityStr);

    // finds the creator User object from global list
    User* creator = nullptr;
    for(User* user : allUsers){
        if(user->getUsername() == creatorName){
            creator = user;
            break;
        }
    }

    // this creates a new webinar instance
    Webinar* webinar = new Webinar(name, creator, desc, platform, date, time, capacity, host);

    // processes all registrants listed after the main attributes
    while(getline(ss, registrar, '|')){
        // find each registrant in global user list
        for(User* user : allUsers){
            if(registrar == user->getUsername())
                webinar->addRegistrar(user);
        }
    }
    return webinar;
}

////////////////////////////   Workshop   ////////////////////////

Workshop::Workshop(){} // a default constructor
Workshop::Workshop(string n, User* creator, string desc, string p, string d, string t, int c, string i)
    : Event(n, creator, desc, p, d, t, c, 0), instructor(i) {} // a parameterised constructor

// getter functions for type and instructor
string Workshop::getType() const{ return "Workshop";}
string Workshop::getInstructor() const{ return instructor;}

// a function that displays the workshop's info
void Workshop::displayDetails() const {
    cout << "Event: " << getName() << " (" << getType() << ")" << endl;
    cout << "Creator: " << (getCreator() ? getCreator()->getUsername() : "Unknown") << endl;
    cout << "Date: " << getDate() << " at " << getTime() << endl;
    cout << "Platform: " << getPlatform() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Capacity: " << getCapacity() << endl;
    cout << "Instructor: " << getInstructor() << endl;
}

// a static factory method implementation which is an interactive workshop event creation function
Event* Workshop::create_event(User* creator){
    // temp variables to store the event's info
    string name, desc, platform, date, time, instructor;
    int capacity;
    cin.ignore(); // clears input buffer
    // gathers event's info
    cout << "Enter event name: ";
    getline(cin, name);
    cout << "Enter description: ";
    getline(cin, desc);
    cout << "Enter platform: ";
    getline(cin, platform);
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);
    while((date[4] != '-') || (date[7] != '-'))  { // format check
        cout << "Wrong format!" << endl << "Enter date (YYYY-MM-DD): ";
        getline(cin, date);
    }
    cout << "Enter time (HH:MM): ";
    getline(cin, time);
    while(time[2] != ':') { // format check
        cout << "Wrong format!" << endl << "Enter time (HH:MM): ";
        getline(cin, time);
    }
    while (true) {
        cout << "Enter capacity: ";
        cin >> capacity;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        }
        else break;
    }
    cin.ignore();
    cout << "Enter Instructor: ";
    getline(cin, instructor);

    // creates and returns a new Webinar object
    Workshop* workshop = new Workshop(name, creator, desc, platform, date, time, capacity, instructor);
    return workshop;
}

// a function that saves collected info into a file
void Workshop::saveToFile(ofstream& file){ // append mode
    // writes down all the info into the file
    file << getType() << "|"
        << creator_name << "|"
        << event_name << "|"
        << description << "|"
        << date << "|"
        << time << "|"
        << platform << "|"
        << capacity << "|"
        << instructor << "|";
    // writes down all registrant usernames
    for(User* registrar : registrars){
        file << registrar->getUsername() << "|";
    }
    file << endl;
}

// a function that creates a workshop object by loading info from a file
Event* Workshop::loadFromFile(const string& line){
    stringstream ss(line);
    string creatorName, name, desc, date, time, platform, capacityStr, instructor, type, registrar;
    // go through the core event attributes from the string
    getline(ss, type, '|');
    getline(ss, creatorName, '|');
    getline(ss, name, '|');
    getline(ss, desc, '|');
    getline(ss, date, '|');
    getline(ss, time, '|');
    getline(ss, platform, '|');
    getline(ss, capacityStr, '|');
    getline(ss, instructor, '|');

    // converts the numeric values
    int capacity = stoi(capacityStr);

    // finds the creator User object from global list
    User* creator = nullptr;

    for(User* user : allUsers){
        if(user->getUsername() == creatorName){
            creator = user; // set the creator pointer when found
            break;
        }
    }

    // this creates a new workshop instance
    Workshop* workshop = new Workshop(name, creator, desc, platform, date, time, capacity, instructor);
    // processes all registrants listed after the main attributes
    while(getline(ss, registrar, '|')){
        for(User* user : allUsers){
            if(registrar == user->getUsername())
                workshop->addRegistrar(user);
        }
    }
    return workshop;
}

////////////////////////   Feedback   ////////////////////////////

Feedback::Feedback()
    : submissionTimestamp_(getCurrentTimestamp()),
      generalRating_(-1)
{}

Feedback::Feedback(const string& reviewerUsername,
                   const string& eventName,
                   const string& eventType,
                   const string& eventDate)
    : reviewerUsername_(reviewerUsername),
      eventName_(eventName),
      eventType_(eventType),
      submissionTimestamp_(getCurrentTimestamp()),
      generalRating_(-1),
      eventDate_(eventDate)
{}

// Observer functions
void Feedback::attach(Observer* observer) {
    observers_.push_back(observer);
}
void Feedback::detach(Observer* observer) {
    observers_.erase(remove(observers_.begin(), observers_.end(), observer), observers_.end());
}
void Feedback::notify() {
    for (Observer* observer : observers_) {
        observer->update(eventName_, "New feedback received by " + reviewerUsername_);
    }
}

// --- General Event Rating ---
void Feedback::setGeneralRating(int rating) {
    if (rating >= 1 && rating <= 5)
        generalRating_ = rating;
    else
        generalRating_ = -1;
}

int Feedback::getGeneralRating() const {return generalRating_;}

// --- Detailed Ratings for Specific Aspects ---

void Feedback::setDetailedRating(const string& aspect, int rating) {
    if (rating >= 1 && rating <= 5) {
        detailedRatings_[aspect] = rating;
    }
}

int Feedback::getDetailedRating(const string& aspect) const {
    auto it = detailedRatings_.find(aspect);
    return (it != detailedRatings_.end()) ? it->second : 0;
}

const map<string, int>& Feedback::getAllDetailedRatings() const {return detailedRatings_;}

// ---Written Feedback (Qualitative Feedback) ---

void Feedback::setImprovementSuggestion(const string& suggestion) {improvementSuggestion_ = suggestion;}

string Feedback::getImprovementSuggestion() const {return improvementSuggestion_;}

// ------------------------------------------------- Display Functionality --------------------------------------------------------------------
// displays feedback details (takes bool that it ture if event is still in the future)
void Feedback::display(bool showFutureNotice) const {
    if (showFutureNotice && isSubmittedBeforeEvent()) {
        cout << "Notice: The event has not been launched yet. Feedback submission is not allowed." << endl;
        cout << "-------------------------------------------------" << endl;
    }
    cout << "--- Feedback for: " << eventName_ << " (" << eventType_ << ") ---" << endl;
    cout << "Submitted by: " << reviewerUsername_ << " on " << submissionTimestamp_ << endl;
    if (generalRating_ != -1) {cout << "General Event Rating: " << generalRating_ << "/5" << endl;}
    cout << "\nDetailed Ratings (1-5):" << endl;
    if (detailedRatings_.empty()) {
        cout << "  (No detailed ratings given)" << endl;
    } else {
        map<string, int> sortedRatings = detailedRatings_;
        for (const auto& pair : sortedRatings) {
            cout << "  - " << pair.first << ": " << pair.second << "/5" << endl;
        }
    }
    if (!improvementSuggestion_.empty()) {
        cout << "  Suggestion for Improvement: " << improvementSuggestion_ << endl;
    }
    cout << "-----------------------------------------" << endl;
}

// checks if feedback is submitted before event time
bool Feedback::isSubmittedBeforeEvent() const {
    // If no event date is set, allow feedback
    if (eventDate_.empty()) return false;

    // Get the current system time
    time_t now = time(nullptr);

    // Convert the event date string to a time object
    time_t eventTime = convertTimestampToTime(eventDate_);

    // If conversion fails, allow feedback
    if (eventTime == -1) return false;

    // If the current time is earlier than the event time, block feedback
    return now < eventTime;
}

// converts date and time to timestamp to use later
time_t Feedback::convertTimestampToTime(const string& timestamp) {
    std::tm tm = {}; // Initialize an empty tm structure
    std::istringstream ss(timestamp); // Create a stream from the timestamp string
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); // Read the time in a specific format
    return mktime(&tm); // Convert the tm structure into a time_t value
}

// ----------------------------------------------------------- Interaction Method -------------------------------------------------------------

// Open feedback Menu (takes vector of events not created by user)
bool Feedback::collectFeedbackInteractive(const vector<string>& potentialAspects) {
    submissionTimestamp_ = getCurrentTimestamp();
    if (isSubmittedBeforeEvent()) {
        return false;
    }
    cout << "\n--- Providing Feedback for: " << eventName_ << " ---" << endl;
    cout << "Help us improve! Please share your thoughts." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // 1. Ask for General Event Rating
    int genRating = -1;
    cout << "On a scale of 0-5, please rate the event overall. ";
    while (!(cin >> genRating) || genRating < 1 || genRating > 5) {
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    setGeneralRating(genRating);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // 2. Ask for Ratings on Different Aspects (optional)
    if (!potentialAspects.empty()) {
        cout << "\nPlease rate the following aspects (1-5, where 1=Poor, 5=Excellent, 0=Skip):" << endl;
        for (const auto& aspect : potentialAspects) {
            int rating = -1;
            cout << "  - " << aspect << ": ";
            while (!(cin >> rating) || rating < 0 || rating > 5) {
                cout << "Invalid input. Please enter a number between 0 and 5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (rating > 0) { setDetailedRating(aspect, rating); }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // 3. Ask for Suggestions
    cout << "Do you have any specific suggestions for how we could improve next time? (Press Enter to skip)\n> ";
    getline(cin, improvementSuggestion_);
    cout << "\nThank you for your valuable feedback!" << endl;
    loadingAnimation(3);
    return true;
}


// Saves feedback to file using a readable structure
void Feedback::saveToFile() const {
    string filename = reviewerUsername_ + "_feedback.txt";
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cout << "Error saving feedback!" << endl;
        return;
    }
    outfile << "--- Feedback Start ---" << endl;
    outfile << "User: " << reviewerUsername_ << endl;
    outfile << "Event: " << eventName_ << endl;
    outfile << "Type: " << eventType_ << endl;
    outfile << "Timestamp: " << submissionTimestamp_ << endl;
    outfile << "generalRating: " << generalRating_ << endl;
    outfile << "Suggestion: " << improvementSuggestion_ << endl;
    outfile << "Ratings: ";
    bool first = true;
    for (const auto& pair : detailedRatings_) {
        if (!first) outfile << " ";
        outfile << pair.first << "=" << pair.second << ";";
        first = false;
    }
    outfile << endl;
    outfile << "--- Feedback End ---" << endl;
    outfile.close();
}


// Get current time from a device
string Feedback::getCurrentTimestamp() {
    auto now = chrono::system_clock::now(); // Get current time
    auto now_c = chrono::system_clock::to_time_t(now); // Convert to time_t
    stringstream ss;

    tm timeinfo;
    localtime_s(&timeinfo, &now_c); // Safely convert to tm structure

    ss << put_time(&timeinfo, "%Y-%m-%d %H:%M:%S"); // Format time nicely

    return ss.str();
}

// This function lets a user review all feedbacks they have submitted
void Feedback::review_feedbacks(User* user) {
    string userName = user->getUsername();
    string filename = userName + "_feedback.txt";
    ifstream infile(filename);
    if (!infile.is_open()) {
        // If a feedback file not found, inform the user and exit
        cout << "\nNo previous feedbacks found for user: " << userName << endl;
        loadingAnimation(3);
        return;
    }

    // Prepare to store all feedbacks
    vector<Feedback> feedbacks;
    string line;
    // Temporary variables to hold feedback data while reading
    string eventName, eventType, eventDate, reviewer, timestamp, suggestion;
    int generalRating = -1;
    map<string, int> detailedRatings;

    // Read the file line by line
    while (getline(infile, line)) {
        if (line == "--- Feedback Start ---") {
            // Start of a new feedback block: reset all temp variables
            eventName = eventType = eventDate = reviewer = timestamp = suggestion = "";
            generalRating = -1;
            detailedRatings.clear();
        } else if (line == "--- Feedback End ---") {
            // End of a feedback block: if we have an event name, create a Feedback object
            if (!eventName.empty()) {
                Feedback fb(reviewer, eventName, eventType, eventDate);
                fb.setGeneralRating(generalRating);
                for (const auto& p : detailedRatings) fb.setDetailedRating(p.first, p.second);
                fb.setImprovementSuggestion(suggestion);
                feedbacks.push_back(fb);
            }
        } else if (!line.empty()) {
            // Parse each line in the feedback block
            if (line.find("User: ") == 0) {
                reviewer = line.substr(6);
            } else if (line.find("Event: ") == 0) {
                eventName = line.substr(7);
            } else if (line.find("Type: ") == 0) {
                eventType = line.substr(6);
            } else if (line.find("Timestamp: ") == 0) {
                timestamp = line.substr(11);
            } else if (line.find("GeneralRating: ") == 0) {
                generalRating = stoi(line.substr(14));
            } else if (line.find("Suggestion: ") == 0) {
                suggestion = line.substr(12);
            } else if (line.find("Ratings: ") == 0) {
                // Parse aspect ratings (e.g., Content=4; Delivery=5; ...)
                string ratings = line.substr(9);
                stringstream ss(ratings);
                string pair;
                while (getline(ss, pair, ';')) {
                    size_t eq = pair.find('=');
                    if (eq != string::npos) {
                        string aspect = pair.substr(0, eq);
                        int val = stoi(pair.substr(eq + 1));
                        if (!aspect.empty()) detailedRatings[aspect] = val;
                    }
                }
            }
        }
    }
    infile.close();

    // If no feedbacks were found, inform the user
    if (feedbacks.empty()) {
        cout << "No feedback entries found." << endl;
        loadingAnimation(3);
        return;
    }

    // Display all feedbacks using the Feedback::display method
    cout << "\n--- Your Feedback Entries ---" << endl;
    int idx = 1;
    for (auto& fb : feedbacks) {
        cout << "\nFeedback #" << idx++ << ":\n";
        fb.display(false); // Do not show the 'event not launched' notice
    }
    loadingAnimation(3);
}

////////////////////////////////////////////////////////////////////////////////

// a function that prints all elements in a set with formatted display
template <typename T> void printMultiset(const set<T>& mset) {
    cout << "Meetings:\n" << "-----------------------------" << endl;
    for (const T& value : mset) {
        value->displayDetails();  // calls the displayDetails() method
        cout << "-----------------------------" << endl;  // optional separator
    }
    cout << endl;
}

// a function for the user to signup
void signup(){
    while(true){
        string inUsername, inPassword, inEmail, inAffiliation; // temp variables to store info
        bool found = false;

        cout << "Enter username: ";
        getline(cin >> ws, inUsername);

        for(User* user : allUsers){ // checks for all users if the username input is already taken
            if(*user == inUsername){
                cout << "Username is taken!" << endl;
                found = true;
                break;
                }
        }
        if(found) continue;

        // continues to ask the user to input their personal info
        cout << "Enter password: ";
        getline(cin >> ws, inPassword);

        cout << "Enter email: ";
        getline(cin >> ws, inEmail);

        cout << "Enter affiliation (optional - press enter to skip): ";
        getline(cin, inAffiliation);

        // this creates a new User object and adds it to the global user registry
        User* user = new User(inUsername, inPassword, inEmail, inAffiliation);
        allUsers.insert(user);

        cout << "Signup successful!" << endl;
        loadingAnimation(3);
        break;
    }

}

// a function for the user to log in
User* login() {
    while (true) {
    string inUsername, inPassword, inEmail, inAffiliation; // temp variables to store info
    bool loginSuccess = false;

        cout << "Enter username: ";
        getline(cin >> ws, inUsername);
        cout << "Enter password: ";
        getline(cin >> ws, inPassword);

        for(User* user : allUsers){
            // case-sensitive comparison
            if(*user == inUsername && inPassword == user->getPassword()){
                cout << "\nWelcome, " << inUsername << "!" << endl;
                return user; // return the existing user pointer
            }
        }
        cout << "Invalid username or password!" << endl;
        return nullptr; // returns authenticated user pointer
    }
}

// a function to load the user's info into a file
void loadUsersData(){
    string username, password, email, affiliation, line; // temp variables
    ifstream usersFile("users.txt"); // opens the file to read

    while (getline(usersFile, line)) {
        stringstream ss(line);
        ss >> username >> password >> email >> ws; //ws to discard the white space
        getline(ss, affiliation);
        allUsers.insert(new User(username, password, email, affiliation));
    }
    usersFile.close();
}

// a function to load the event's info into a file
void loadEventsData(){
    string type, line;

    ifstream eventsFile("events.txt"); // open the file to read

    while(getline(eventsFile, line)) {
        stringstream ss(line);
        getline(ss, type, '|');
        if(type == "Conference"){
            allEvents.insert(Conference::loadFromFile(line));
        }
        else if(type == "Webinar"){
            allEvents.insert(Webinar::loadFromFile(line));
        }
        else if(type == "Workshop"){
            allEvents.insert(Workshop::loadFromFile(line));
        }
    }
    eventsFile.close();
}

// a function that saves the user's info file
void saveUsersToFile(){
    ofstream usersFile("users.txt", ios::out | ios::trunc);  // Open once and truncate
    if (!usersFile.is_open()) { // error
        cout << "Error opening file." << endl;
        return;
    }
    // saves info into file
    for(User* user : allUsers){
        usersFile << user->getUsername() << " " << user->getPassword() << " " << user->getEmail() << " " << user->getAffiliation() << endl;
    }
    usersFile.close();
}

// a function that saves the event's info into file
void saveEventsToFile(){
    ofstream file("events.txt", ios::out | ios::trunc);  // Open once and truncate

    if (!file.is_open()) { // error
        cerr << "Error opening file." << endl;
        return;
    }

    for(Event* event : allEvents){
        event->saveToFile(file); // saves the info
    }
    file.close();
}

// a function that displays a simple animated loading indicator
void loadingAnimation(int seconds) {
    for (int i = 0; i < seconds; i++) {
        cout << "." << std::flush; // print dot and immediately flush output
        // pause execution for visual effect
        this_thread::sleep_for(chrono::milliseconds(500));  // 0.5 second delay
    }
    cout << endl;
}

int main() {
    Menu menu;
    menu.setup();
    return 0;
}
