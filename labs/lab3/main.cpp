import std;
import gamelib;
import Character;


int main() {
	hello(3);
    Character p1(100, 10, 50, 20, 5, 3);
    Character p2(100, 10, 50, 20, 5, 3);
    
    int pc_or_player = int_input();
    std::println("0 - pc, other - human");
    switch(pc_or_player) {
    case 0:
        play_pc(p1, p2);
        break;
    default:
        play(p1, p2);
        break;
    }
    
    return 0;
}