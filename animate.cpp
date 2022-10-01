#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"


animate::animate():sidebar(WORK_PANEL, SIDE_BAR)
{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing Calculator");
    system = System(_funciton,_originX,_originY,_numOfdots,_low,_high);
    window.setFramerateLimit(60);
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    loadFile();
    cout<<"animate construct!"<<endl;

    myTextLabel = sf::Text("+", font);
    myTextLabel.setCharacterSize(30);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color::White);
    myTextLabel.setPosition(sf::Vector2f(1300, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-600));

    myTextLabel2 = sf::Text("-", font);
    myTextLabel2.setCharacterSize(30);
    myTextLabel2.setStyle(sf::Text::Bold);
    myTextLabel2.setColor(sf::Color::White);
    myTextLabel2.setPosition(sf::Vector2f(1350, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-600));

    myTextLabel3 = sf::Text("*", font);
    myTextLabel3.setCharacterSize(30);
    myTextLabel3.setStyle(sf::Text::Bold);
    myTextLabel3.setColor(sf::Color::White);
    myTextLabel3.setPosition(sf::Vector2f(1400, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-600));

    myTextLabel4 = sf::Text("/", font);
    myTextLabel4.setCharacterSize(30);
    myTextLabel4.setStyle(sf::Text::Bold);
    myTextLabel4.setColor(sf::Color::White);
    myTextLabel4.setPosition(sf::Vector2f(1450, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-600));



    myTextLabel5 = sf::Text("sin", font);
    myTextLabel5.setCharacterSize(30);
    myTextLabel5.setStyle(sf::Text::Bold);
    myTextLabel5.setColor(sf::Color::White);
    myTextLabel5.setPosition(sf::Vector2f(1300, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-550));

    myTextLabel6 = sf::Text("cos", font);
    myTextLabel6.setCharacterSize(30);
    myTextLabel6.setStyle(sf::Text::Bold);
    myTextLabel6.setColor(sf::Color::White);
    myTextLabel6.setPosition(sf::Vector2f(1400, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-550));

    myTextLabel7 = sf::Text("tan", font);
    myTextLabel7.setCharacterSize(30);
    myTextLabel7.setStyle(sf::Text::Bold);
    myTextLabel7.setColor(sf::Color::White);
    myTextLabel7.setPosition(sf::Vector2f(1500, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-550));

    myTextLabel8 = sf::Text("cot", font);
    myTextLabel8.setCharacterSize(30);
    myTextLabel8.setStyle(sf::Text::Bold);
    myTextLabel8.setColor(sf::Color::White);
    myTextLabel8.setPosition(sf::Vector2f(1300, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-500));

    myTextLabel9 = sf::Text("csc", font);
    myTextLabel9.setCharacterSize(30);
    myTextLabel9.setStyle(sf::Text::Bold);
    myTextLabel9.setColor(sf::Color::White);
    myTextLabel9.setPosition(sf::Vector2f(1400, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-500));

    myTextLabel10 = sf::Text("sec", font);
    myTextLabel10.setCharacterSize(30);
    myTextLabel10.setStyle(sf::Text::Bold);
    myTextLabel10.setColor(sf::Color::White);
    myTextLabel10.setPosition(sf::Vector2f(1500, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-500));
    //num1
    myTextLabel11 = sf::Text("1", font);
    myTextLabel11.setCharacterSize(30);
    myTextLabel11.setStyle(sf::Text::Bold);
    myTextLabel11.setColor(sf::Color::White);
    myTextLabel11.setPosition(sf::Vector2f(1300, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-450));

    myTextLabel12 = sf::Text("2", font);
    myTextLabel12.setCharacterSize(30);
    myTextLabel12.setStyle(sf::Text::Bold);
    myTextLabel12.setColor(sf::Color::White);
    myTextLabel12.setPosition(sf::Vector2f(1400, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-450));

    myTextLabel13 = sf::Text("3", font);
    myTextLabel13.setCharacterSize(30);
    myTextLabel13.setStyle(sf::Text::Bold);
    myTextLabel13.setColor(sf::Color::White);
    myTextLabel13.setPosition(sf::Vector2f(1500, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-450));

    myTextLabel14 = sf::Text("4", font);
    myTextLabel14.setCharacterSize(30);
    myTextLabel14.setStyle(sf::Text::Bold);
    myTextLabel14.setColor(sf::Color::White);
    myTextLabel14.setPosition(sf::Vector2f(1300, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-400));

    myTextLabel15 = sf::Text("5", font);
    myTextLabel15.setCharacterSize(30);
    myTextLabel15.setStyle(sf::Text::Bold);
    myTextLabel15.setColor(sf::Color::White);
    myTextLabel15.setPosition(sf::Vector2f(1400, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-400));

    myTextLabel16 = sf::Text("6", font);
    myTextLabel16.setCharacterSize(30);
    myTextLabel16.setStyle(sf::Text::Bold);
    myTextLabel16.setColor(sf::Color::White);
    myTextLabel16.setPosition(sf::Vector2f(1500, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-400));

    myTextLabel17 = sf::Text("7", font);
    myTextLabel17.setCharacterSize(30);
    myTextLabel17.setStyle(sf::Text::Bold);
    myTextLabel17.setColor(sf::Color::White);
    myTextLabel17.setPosition(sf::Vector2f(1300, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-350));

    myTextLabel18 = sf::Text("8", font);
    myTextLabel18.setCharacterSize(30);
    myTextLabel18.setStyle(sf::Text::Bold);
    myTextLabel18.setColor(sf::Color::White);
    myTextLabel18.setPosition(sf::Vector2f(1400, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-350));

    myTextLabel19 = sf::Text("9", font);
    myTextLabel19.setCharacterSize(30);
    myTextLabel19.setStyle(sf::Text::Bold);
    myTextLabel19.setColor(sf::Color::White);
    myTextLabel19.setPosition(sf::Vector2f(1500, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-350));

    myTextLabel20 = sf::Text("(", font);
    myTextLabel20.setCharacterSize(30);
    myTextLabel20.setStyle(sf::Text::Bold);
    myTextLabel20.setColor(sf::Color::White);
    myTextLabel20.setPosition(sf::Vector2f(1300, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-300));

    myTextLabel21 = sf::Text("0", font);
    myTextLabel21.setCharacterSize(30);
    myTextLabel21.setStyle(sf::Text::Bold);
    myTextLabel21.setColor(sf::Color::White);
    myTextLabel21.setPosition(sf::Vector2f(1400, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-300));

    myTextLabel22 = sf::Text(")", font);
    myTextLabel22.setCharacterSize(30);
    myTextLabel22.setStyle(sf::Text::Bold);
    myTextLabel22.setColor(sf::Color::White);
    myTextLabel22.setPosition(sf::Vector2f(1500, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-300));

    myTextLabel23 = sf::Text("=", font);
    myTextLabel23.setCharacterSize(30);
    myTextLabel23.setStyle(sf::Text::Bold);
    myTextLabel23.setColor(sf::Color::White);
    myTextLabel23.setPosition(sf::Vector2f(1300, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-250));

    myTextLabel24 = sf::Text("x", font);
    myTextLabel24.setCharacterSize(30);
    myTextLabel24.setStyle(sf::Text::Bold);
    myTextLabel24.setColor(sf::Color::White);
    myTextLabel24.setPosition(sf::Vector2f(1400, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-250));

    myTextLabel25 = sf::Text("c", font);
    myTextLabel25.setCharacterSize(30);
    myTextLabel25.setStyle(sf::Text::Bold);
    myTextLabel25.setColor(sf::Color::White);
    myTextLabel25.setPosition(sf::Vector2f(1500, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-250));

    myTextLabel26 = sf::Text("^", font);
    myTextLabel26.setCharacterSize(30);
    myTextLabel26.setStyle(sf::Text::Bold);
    myTextLabel26.setColor(sf::Color::White);
    myTextLabel26.setPosition(sf::Vector2f(1500, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-600));

    myTextLabel27 = sf::Text("+", font);
    myTextLabel27.setCharacterSize(50);
    myTextLabel27.setStyle(sf::Text::Regular);
    myTextLabel27.setColor(sf::Color::Cyan);
    myTextLabel27.setPosition(sf::Vector2f(1220, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-250));

    myTextLabel28 = sf::Text("-", font);
    myTextLabel28.setCharacterSize(50);
    myTextLabel28.setStyle(sf::Text::Regular);
    myTextLabel28.setColor(sf::Color::Cyan);
    myTextLabel28.setPosition(sf::Vector2f(1225, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-210));

    myTextLabel29 = sf::Text("R", font);
    myTextLabel29.setCharacterSize(35);
    myTextLabel29.setStyle(sf::Text::Regular);
    myTextLabel29.setColor(sf::Color::Cyan);
    myTextLabel29.setPosition(sf::Vector2f(1220, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-150));

}

void animate::Draw(){
    system.Draw(window);
    sidebar.draw(window);
    window.draw(myTextLabel);
    window.draw(myTextLabel2);
    window.draw(myTextLabel3);
    window.draw(myTextLabel4);
    window.draw(myTextLabel5);
    window.draw(myTextLabel6);
    window.draw(myTextLabel7);
    window.draw(myTextLabel8);
    window.draw(myTextLabel9);
    window.draw(myTextLabel10);
    //number
    window.draw(myTextLabel11);
    window.draw(myTextLabel12);
    window.draw(myTextLabel13);
    window.draw(myTextLabel14);
    window.draw(myTextLabel15);
    window.draw(myTextLabel16);
    window.draw(myTextLabel17);
    window.draw(myTextLabel18);
    window.draw(myTextLabel19);
    window.draw(myTextLabel20);
    window.draw(myTextLabel21);
    window.draw(myTextLabel22);
    //equal x clear
    window.draw(myTextLabel23);
    window.draw(myTextLabel24);
    window.draw(myTextLabel25);

    window.draw(myTextLabel26);

    window.draw(myTextLabel27);
    window.draw(myTextLabel28);
    window.draw(myTextLabel29);

}

void animate::update(){
    if(update_){
//        cout << "updated has been called!" << endl;
        system.update(_funciton,_originX,_originY,_numOfdots,_low,_high);
        update_ = false;
        cout << "updated has been finished!" << endl;
    }
}

void animate::render(){
       window.clear();
       Draw();
       window.display();
}

void animate::processEvents()
{
   sf::Event event;
   while (window.pollEvent(event))
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;
               //-------------------------------------TEXT---------------------------------------------------
                          case sf::Event::TextEntered://when input text
                          {

                              if(INPUT == true)
                              {
                                 if (event.text.unicode < 128 )
                                 {
                                     if(event.text.unicode == 8){//delete...
//                                         cout << "here you are2 !" << endl;
                                         if(!sidebar[2].empty()){
//                                             cout << "here you are1 !" << endl;
                                             sidebar[2].pop_back();
                                         }
                                     }

                                     else if(event.text.unicode != 10)//the type of 'enter' is 10, problem solved!
                                     {
               //                          cout << "here you are3 !" << endl;
               //                          cout << " static_cast<char>(event.text.unicode) is" <<  static_cast<char>(event.text.unicode)<<"!" << endl;
//                                         cout << "side bar 2 now is" << sidebar[2] << "!!" << endl;
                                         sidebar[2] += static_cast<char>(event.text.unicode);

                                     }
//                                         cout << "side bar 2 now is" << sidebar[2] << "!!" << endl;
                                  }
                              }
                              break;
                           }
           //----------------------------------- key pressed---------------------------------------------
           case sf::Event::KeyPressed:

               switch(event.key.code){
                    //when return was pressed
                 case sf::Keyboard::Return:
                   sidebar[SB_KEY_PRESSED] = "INPUT MODE";
                   if(INPUT == false){
                       //if we are not in input mode, change the status of false to true, then we are in input mode
                       INPUT = true;
                   }
                   else{
                       //if we are in the input mode,
                       //first check if there's anything in the bar
                       if(check(sidebar[2]) && !sidebar[2].empty()){
                           sidebar[0] = "f(x) = " + sidebar[2];
                           _funciton = sidebar[2];
                           sidebar[2].clear();
                           sidebar[1].clear();
                           INPUT = false;
                           update_ = true;
                       }
                       else{//if there is alreadty something in sidebar[2]. clear them
                           sidebar[0] = "INVALID INPUT";
                           sidebar[1].clear();
                           sidebar[2].clear();
                           INPUT = false;
                       }
                   }
//                   cout << "sidebar 2 after pressing input is" << sidebar[2] << "!!!" << endl;

                   break;
                case sf::Keyboard::N:
                   {
                   if(!INPUT){
                       sidebar[SB_KEY_PRESSED] = "ZOOM IN";
                       _low /=1.1;
                       _high /=1.1;
                       update_ = true;
                        }
                    }
                   break;
               case sf::Keyboard::M:
               {
                   if(!INPUT){
                       sidebar[SB_KEY_PRESSED] = "ZOOM OUT";
                       _low *=1.1;
                       _high *=1.1;
                       update_ = true;
                   }
               }
                   break;

               case sf::Keyboard::R:
               {

                       sidebar[SB_KEY_PRESSED] = "RESET";
                       _low = -20;
                       _high = 20;
                       _originX = 640;
                       _originY = 600;

                   update_ = true;
               }
                   break;

               case sf::Keyboard::T:
               {
                   if(!INPUT){
                    sidebar[SB_KEY_PRESSED] = "SAVE FILE";
                   saveFunction();
                   saveFile();
                   }
               }
                   break;

               case sf::Keyboard::Left:
               {
                   if(!INPUT){
                       sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                       _low -=1;
                       _high -=1;
                       _size = system.getSize();
                       _originX += _size;

                       update_ = true;
                       cout << "left, origin(" << _originX << ", " << _originY << ")" << endl;
                   }
               }
                   break;
               case sf::Keyboard::Right:
               {
                   if(!INPUT){
                       sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                       _low +=1;
                       _high +=1;
                       _size = system.getSize();
                       _originX -= _size;
                       update_ = true;
                       cout << "right, origin(" << _originX << ", " << _originY << ")" << endl;
                   }
                }
                   break;
               case sf::Keyboard::Up:
               {
                   if(!INPUT){
                       sidebar[SB_KEY_PRESSED] = "UP ARROW";
                       _originY += 20;
                       update_ = true;
                       cout << "up, origin(" << _originX << ", " << _originY << ")" << endl;
                   }
               }
                   break;
               case sf::Keyboard::Down:
               {
                   if(!INPUT){
                       sidebar[SB_KEY_PRESSED] = "DOWN ARROW";
                       _originY -= 20;
                       update_ = true;
                       cout << "down, origin(" << _originX << ", " << _originY << ")" << endl;
                   }
               }
                   break;
               case sf::Keyboard::Escape:
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                   break;
               }
               break; // key press break


//-----------------------------------MOUSE------------------------------------------------------------
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

//           case sf::Event::MouseMoved:
//                if (mouseIn){
//                    //mousePoint red dot:
//                    mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
//                                           sf::Mouse::getPosition(window).y-5);

//                    //mouse location text for sidebar:
//                    sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
//                }
//               break;
          case sf::Event::MouseButtonPressed:  // action from the mouse
               if (event.mouseButton.button == sf::Mouse::Right){  // right click the mouse
                       cout << "mouse x: " << event.mouseButton.x << endl;   // the position of mouse will show up on screen
                       cout << "mouse y: " << event.mouseButton.y << endl;
                       saveFunction();
                       saveFile();
               }
               if (event.mouseButton.button ==  sf::Mouse::Left){  // left mouse click
                   cout << "left click" << endl;
                   loadFunction();
                   sidebar[0] = "f(x) = " + _funciton;
               }
               break;
           case sf::Event::MouseButtonReleased:
                   break;
           }
       }

}


void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}

bool animate::check(string a){
    try {
        string carrier;
        int count_left = 0;
        int count_right = 0;

        if(a.empty()){
            throw 1;
        }

        for(int i=0; a[i]!= NULL; i++){
            switch (a[i]) {
            case 's':
            case 'c':
            case 't':
            {
                int count = 3;
                while (count !=0) {
                    carrier = carrier + a[i];
                    count--;
                    i++;
                }
                i--;
                if(carrier != "sin" && carrier != "sec" && carrier != "cos" && carrier != "csc" && carrier != "cot" && carrier != "tan"){
                    throw 2;
                }
                if(a[i+1] != '('){
                    throw 3;
                }
                carrier.clear();
            }
                break;
            case 'p':
            {
                carrier = carrier + a[i];
                i++;
                carrier = carrier + a[i];
                if(carrier != "pi"){
                    throw 4;
                }
                carrier.clear();
            }
                break;
            case '(':
            {
                if(a[i+1] == ')'){
                    throw  5;
                }
                count_left++;
            }
                break;
            case ')':
            {
                 count_right++;
            }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if(i == 0 && a[i] != '-'){
                    throw 6;
                }
                if(a[i+1] == NULL){
                    throw 7;
                }
                if(!find(a[i-i]) && !find(a[i+1])){
                    throw 8;
                }
                break;
            default:
            {
                if(!find(a[i])){//some problem here!!!!
                    throw 9;
                }
            }
                break;


            }
        }
    } catch (int x) {
        switch (x) {
        case 1:
            cout << "empty input" << endl;
            return false;
        case 2:
            cout << "incomplete input for trig" << endl;
            return false;
        case 3:
            cout << "incomplete input for trig, missing value after the trig" << endl;
            return false;
        case 4:
            cout << "incomplete input for pi" << endl;
            return  false;
        case 5:
            cout << "missing value inside the ()" << endl;
            return false;
        case 6:
            cout << "operator at the beginning" << endl;
            return false;
        case 7:
            cout << "operator at the end" << endl;
            return false;
        case 8:
            cout << "wrong position for operator" << endl;
            return false;
        case 9:
            cout << "invalid input 999" << endl;
            return false;
        }
    }
    return true;
}

bool animate::find(char a){
    string b = "1234567890+-*/^pix";
    int count = 0;
    for(int i=0; b[i]!= NULL; i++){
        if(a == b[i]){
            count++;
        }
    }
    if(count != 0){
        return true;
    }
    else{
        cout << "cannot find the charactor" << endl;
        return false;
    }
}

double animate::increment(){
    double domain;
    if(_high < 0){
        domain = (abs(_low)-abs(_high));
    }
    else if(_low > 0){
        domain = (abs(_high)-abs(_low));
    }
    else{
        domain = (abs(_low)+abs(_high));
    }

    return domain / _numOfdots;
}

void animate::saveFile(){
    cout << "Filed has been Saved!!!!!!!!!" << endl;
    // maximum spaces to save is 17. (until 27)
    ofstream outfile;  // initilize
    outfile.open("SAVE.txt");  // open the file
    for(int i= 4; i<19; i++){
        if(!sidebar[i].empty()){
            outfile << sidebar[i] << endl;
        }
    }
    cout << __LINE__  << endl;
    outfile.close(); // output done
}

void animate::loadFile(){
    cout << "Filed Loaded!!!!!!!!!!!!!" << endl;
    ifstream infile;
    infile.open("SAVE.txt"); // read the text file
    string carrier;
    int i = 4;  // fill in the sidebar start at 4
    while(infile){
        getline(infile,carrier);   // default is \n, when it see the \n function will move to the next line
        sidebar[i] = carrier;
        i++;
    }
    infile.close(); // input done
//    cout << __LINE__ << endl;


}

void animate::loadFunction(){

    if(sf::Mouse::getPosition(window).x >= 1290 && sf::Mouse::getPosition(window).x <= 1320 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 590 && sf::Mouse::getPosition(window).y <= 620){
        cout << "pressed " << endl;
             sidebar[2] += "+" ;
            cout << " + pressed" << endl;
        }


    if(sf::Mouse::getPosition(window).x >= 1320 && sf::Mouse::getPosition(window).x <= 1375 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 590 && sf::Mouse::getPosition(window).y <= 620){
        cout << "pressed " << endl;
             sidebar[2] += "-" ;
            cout << " - pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1375 && sf::Mouse::getPosition(window).x <= 1425 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 590 && sf::Mouse::getPosition(window).y <= 620){
        cout << "pressed " << endl;
             sidebar[2] += "*" ;
            cout << " * pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1425 && sf::Mouse::getPosition(window).x <= 1474 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 590 && sf::Mouse::getPosition(window).y <= 620){
        cout << "pressed " << endl;
             sidebar[2] += "/" ;
            cout << " / pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1475 && sf::Mouse::getPosition(window).x <= 1525 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 590 && sf::Mouse::getPosition(window).y <= 620){
        cout << "pressed " << endl;
             sidebar[2] += "^" ;
            cout << " ^ pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1290 && sf::Mouse::getPosition(window).x <= 1360 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 638 && sf::Mouse::getPosition(window).y <= 674){
        cout << "pressed " << endl;
             sidebar[2] += "sin" ;
            cout << " sin pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1375 && sf::Mouse::getPosition(window).x <= 1475 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 638 && sf::Mouse::getPosition(window).y <= 674){
        cout << "pressed " << endl;
             sidebar[2] += "cos" ;
            cout << " cos pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1475 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 638 && sf::Mouse::getPosition(window).y <= 674){
        cout << "pressed " << endl;
             sidebar[2] += "tan" ;
            cout << " tan pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1290 && sf::Mouse::getPosition(window).x <= 1360 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 690 && sf::Mouse::getPosition(window).y <= 730){
        cout << "pressed " << endl;
             sidebar[2] += "cot" ;
            cout << " cot pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1375 && sf::Mouse::getPosition(window).x <= 1475 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 690 && sf::Mouse::getPosition(window).y <= 730){
        cout << "pressed " << endl;
             sidebar[2] += "csc" ;
            cout << " csc pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1475 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 690 && sf::Mouse::getPosition(window).y <= 730){
        cout << "pressed " << endl;
             sidebar[2] += "sec" ;
            cout << " sec pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1290 && sf::Mouse::getPosition(window).x <= 1360 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 735 && sf::Mouse::getPosition(window).y <= 780){
        cout << "pressed " << endl;
             sidebar[2] += "1" ;
            cout << " 1 pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1375 && sf::Mouse::getPosition(window).x <= 1475 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 735 && sf::Mouse::getPosition(window).y <= 780){
        cout << "pressed " << endl;
             sidebar[2] += "2" ;
            cout << " 2 pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1475 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 735 && sf::Mouse::getPosition(window).y <= 780){
        cout << "pressed " << endl;
             sidebar[2] += "3" ;
            cout << " 3 pressed" << endl;
        }


    if(sf::Mouse::getPosition(window).x >= 1290 && sf::Mouse::getPosition(window).x <= 1360 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 780 && sf::Mouse::getPosition(window).y <= 830){
        cout << "pressed " << endl;
             sidebar[2] += "4" ;
            cout << " 4 pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1375 && sf::Mouse::getPosition(window).x <= 1475 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 780 && sf::Mouse::getPosition(window).y <= 830){
        cout << "pressed " << endl;
             sidebar[2] += "5" ;
            cout << " 5 pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1475 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 780 && sf::Mouse::getPosition(window).y <= 830){
        cout << "pressed " << endl;
             sidebar[2] += "6" ;
            cout << " 6 pressed" << endl;
        }


    if(sf::Mouse::getPosition(window).x >= 1290 && sf::Mouse::getPosition(window).x <= 1360 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 836 && sf::Mouse::getPosition(window).y <= 880){
        cout << "pressed " << endl;
             sidebar[2] += "7" ;
            cout << " 7 pressed" << endl;
        }


    if(sf::Mouse::getPosition(window).x >= 1375 && sf::Mouse::getPosition(window).x <= 1475 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 836 && sf::Mouse::getPosition(window).y <= 880){
        cout << "pressed " << endl;
             sidebar[2] += "8" ;
            cout << " 8 pressed" << endl;
        }


    if(sf::Mouse::getPosition(window).x >= 1475 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 836 && sf::Mouse::getPosition(window).y <= 880){
        cout << "pressed " << endl;
             sidebar[2] += "9" ;
            cout << " 9 pressed" << endl;
        }


    if(sf::Mouse::getPosition(window).x >= 1290 && sf::Mouse::getPosition(window).x <= 1360 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 890 && sf::Mouse::getPosition(window).y <= 930){
        cout << "pressed " << endl;
             sidebar[2] += "(" ;
            cout << " ( pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1375 && sf::Mouse::getPosition(window).x <= 1475 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 890 && sf::Mouse::getPosition(window).y <= 930){
        cout << "pressed " << endl;
             sidebar[2] += "0" ;
            cout << " 0 pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1475 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 890 && sf::Mouse::getPosition(window).y <= 930){
        cout << "pressed " << endl;
             sidebar[2] += ")" ;
            cout << " ) pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1290 && sf::Mouse::getPosition(window).x <= 1360 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 930 && sf::Mouse::getPosition(window).y <= 975){

        if(check(sidebar[2]) && !sidebar[2].empty()){
            sidebar[0] = "f(x) = " + sidebar[2];
            _funciton = sidebar[2];
            sidebar[2].clear();
            sidebar[1].clear();
            update_ = true;
        }
        else{//if there is alreadty something in sidebar[2]. clear them
            sidebar[0] = "INVALID INPUT";
            sidebar[1].clear();
            sidebar[2].clear();
        }
            cout << " calculate pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1375 && sf::Mouse::getPosition(window).x <= 1475 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 930 && sf::Mouse::getPosition(window).y <= 975){
        cout << "pressed " << endl;
             sidebar[2] += "x" ;
            cout << " x pressed" << endl;
        }

    if(sf::Mouse::getPosition(window).x >= 1475 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 930 && sf::Mouse::getPosition(window).y <= 975){
        cout << "clear pressed " << endl;
        sidebar[2].clear();
        }

    if(sf::Mouse::getPosition(window).x >= 1200 && sf::Mouse::getPosition(window).x <= 1254 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 953 && sf::Mouse::getPosition(window).y <= 988){
       cout << "zoom in" << endl;
       _low /=1.1;
       _high /=1.1;
       update_ = true;
        }


    if(sf::Mouse::getPosition(window).x >= 1200 && sf::Mouse::getPosition(window).x <= 1254 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 988 && sf::Mouse::getPosition(window).y <= 1030){
        cout << "zoom out " << endl;
        _low *=1.1;
        _high *=1.1;
        update_ = true;
        }


    if(sf::Mouse::getPosition(window).x >= 1200 && sf::Mouse::getPosition(window).x <= 1254 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 1030 && sf::Mouse::getPosition(window).y <= 1086){
        cout << "Reset" << endl;
        _low =-20;
        _high = 20;
        _originX =640;
        _originY = 600;
        update_ = true;
        }























    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
            sf::Mouse::getPosition(window).y >= 134 && sf::Mouse::getPosition(window).y <= 165){
        if(!sidebar[4].empty() && !INPUT){

            _funciton = sidebar[4];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 165 && sf::Mouse::getPosition(window).y <= 196){
        cout << "!!!!!!!!!!" << endl;
        if(!sidebar[5].empty() && !INPUT){



            _funciton = sidebar[5];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 196 && sf::Mouse::getPosition(window).y <= 227){
        if(!sidebar[6].empty() && !INPUT){

            _funciton = sidebar[6];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 227 && sf::Mouse::getPosition(window).y <= 258){
        if(!sidebar[7].empty() && !INPUT){

            _funciton = sidebar[7];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 258 && sf::Mouse::getPosition(window).y <= 289){
        if(!sidebar[8].empty() && !INPUT){

            _funciton = sidebar[8];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 289 && sf::Mouse::getPosition(window).y <= 320){
        if(!sidebar[9].empty() && !INPUT){

            _funciton = sidebar[9];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 320 && sf::Mouse::getPosition(window).y <= 351){
        if(!sidebar[10].empty() && !INPUT){

            _funciton = sidebar[10];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 351 && sf::Mouse::getPosition(window).y <= 382){
        if(!sidebar[11].empty() && !INPUT){

            _funciton = sidebar[11];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 382 && sf::Mouse::getPosition(window).y <= 413){
        if(!sidebar[12].empty() && !INPUT){

            _funciton = sidebar[12];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 413 && sf::Mouse::getPosition(window).y <= 444){
        if(!sidebar[13].empty() && !INPUT){

            _funciton = sidebar[13];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 444 && sf::Mouse::getPosition(window).y <= 475){
        if(!sidebar[14].empty() && !INPUT){

            _funciton = sidebar[14];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 475 && sf::Mouse::getPosition(window).y <= 506){
        if(!sidebar[15].empty() && !INPUT){

            _funciton = sidebar[15];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 506 && sf::Mouse::getPosition(window).y <= 537){
        if(!sidebar[16].empty() && !INPUT){

            _funciton = sidebar[16];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 537 && sf::Mouse::getPosition(window).y <= 568){
        if(!sidebar[17].empty() && !INPUT){

            _funciton = sidebar[17];
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y > 568 && sf::Mouse::getPosition(window).y <= 599){
        if(!sidebar[18].empty() && !INPUT){

            _funciton = sidebar[18];
            update_ = true;
            cout << "function changed." << endl;
        }
    }
//    cout << __LINE__ << endl;
}

void animate::saveFunction(){
    cout << __LINE__ << endl;

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&  // the valid range to click buttons
       sf::Mouse::getPosition(window).y >= 134 && sf::Mouse::getPosition(window).y <= 165){
        if(!INPUT){
            sidebar[4] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 165 && sf::Mouse::getPosition(window).y <= 196){
        if(!INPUT){
            sidebar[5] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 196 && sf::Mouse::getPosition(window).y <= 227){
        if(!INPUT){
            sidebar[6] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 227 && sf::Mouse::getPosition(window).y <= 258){
        if(!INPUT){
            sidebar[7] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 258 && sf::Mouse::getPosition(window).y <= 289){
        if(!INPUT){
            sidebar[8] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 289 && sf::Mouse::getPosition(window).y <= 320){
        if(!INPUT){
            sidebar[9] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 320 && sf::Mouse::getPosition(window).y <= 351){
        if(!INPUT){
            sidebar[10] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 351 && sf::Mouse::getPosition(window).y <= 382){
        if(!INPUT){
            sidebar[11] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 382 && sf::Mouse::getPosition(window).y <= 413){
        if(!INPUT){
            sidebar[12] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 413 && sf::Mouse::getPosition(window).y <= 444){
        if(!INPUT){
            sidebar[13] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

    if(sf::Mouse::getPosition(window).x >= 1300 && sf::Mouse::getPosition(window).x <= 1550 &&
       sf::Mouse::getPosition(window).y >= 444 && sf::Mouse::getPosition(window).y <= 475){
        if(!INPUT){
            sidebar[14] = _funciton;
            update_ = true;
            cout << "function changed." << endl;
        }
    }

}






