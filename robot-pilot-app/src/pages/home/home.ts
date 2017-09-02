import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

  public startDirectionX: number = 375;
  public startDirectionY: number = 200;
  public startRotationY: number = 200;
  public directionX: number = 375;
  public directionY: number = 125;
  public roationY: number = 125;

  constructor(public navCtrl: NavController) {

  }

  getDirectionXY(e){
    this.directionX = e.srcEvent.offsetX
    this.directionY = e.srcEvent.offsetY
    if(e.isFinal){
      this.directionX = 375
      this.directionY = 125
    }
  }

  getRoationY(e){
    this.roationY = e.srcEvent.offsetY
    if(this.roationY > 250){
      this.roationY = 250
    }

    else if(this.roationY < 0){
      this.roationY = 0
    }
    if(e.isFinal){
      this.roationY = 125
    }
  }
}
