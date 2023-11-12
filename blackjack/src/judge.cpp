#include <stddef.h>
#include <assert.h>
#include "judge.h"

/// ブラック・ジャックの勝敗判定を行う．
/// ハンドは，ナチュラルブラック・ジャック(1枚がAでもう1枚が絵札か10)が最も強く，
/// それ以外は21に近いほうが強い．ただし，バースト(21を超えた場合)は最も弱い．
/// 勝敗判定は，
/// 1. プレイヤーがバーストすれば自動的にディーラーの勝利
/// 2. 1以外はハンドが強いほうが勝利．同じ場合は引き分け．
///
/// @param dealer_score ディーラーの得点
/// @param player_score プレイヤーの得点
/// @return 1: ディーラーの勝利, 0: 引き分け, -1: プレイヤーの勝利
int judge_score(int dealer_score, int player_score) {
    // ここを実装する
    if(dealer_score == -1){
        dealer_score += 23;
    }
    if(player_score == -1){
        player_score += 23;
    }
    if((player_score == 0) || (dealer_score > player_score)){
        return 1;
    }else if(dealer_score < player_score){
        return -1;
    }
    return 0;
}

/// ブラック・ジャックゲームの手札の得点を計算する．
/// @param cards 手札 (各カードは1から13のいずれか)
/// @param len 手札の枚数 (= 配列cardsの長さ)
/// @return 手札の得点．ただしバーストなら0，ナチュラルブラック・ジャックなら-1を返す．
int calc_score(int cards[], size_t len) {
    // ここを実装する
    int score = 0, ten_count = 0, eleven_count = 0;
    for(int i = 0; i < len; i++){
        if(cards[i] >= 10){
            cards[i] = 10;
            ten_count++;
        }else if(cards[i] == 1){
            if(score + cards[i] + 10 <= 21){
                cards[i] += 10;
                eleven_count++;
            }
        }
        score += cards[i];
    }
    if(score > 21){
        score -= eleven_count * 10;
    }
    if((score == 21) && (ten_count == 1) && (eleven_count == 1)){
        return -1;
    }else if(score <= 21){
        return score;
    }
    return 0;
}
