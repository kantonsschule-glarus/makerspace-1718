import {Component, OnInit} from '@angular/core';
import { NavController } from 'ionic-angular';
import {RobotCommunicationService} from "../../services/robot-communication-service/robot-communication-service";
import {MecanumPage} from "../mecanum/mecanum";

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage implements OnInit {

  public leftThrottleValue: number = 125;
  public rightThrottleValue: number = 125;
  public leftThrottleSpeed: number = 0;
  public rightThrottleSpeed: number = 0;
  public data: number[] = [0,0];

  constructor(public robotCommunicationService: RobotCommunicationService, public navCtrl: NavController) {;}

  ngOnInit(){
//    this.robotCommunicationService.setLeftWheelVelocity(0.2);
//    this.robotCommunicationService.setRightWheelVelocity(-0.2);
  }

  getLeftThrottleValue(e){
    this.leftThrottleValue = e.srcEvent.offsetY

    if(this.leftThrottleValue > 250){
      this.leftThrottleValue = 250
    }
    else if(this.leftThrottleValue < 0){
      this.leftThrottleValue = 0
    }

    if(e.isFinal){
      this.leftThrottleValue = 125
    }
  }

  getRightThrottleValue(e){
    this.rightThrottleValue = e.srcEvent.offsetY

    if(this.rightThrottleValue > 250){
      this.rightThrottleValue = 250
    }
    else if(this.rightThrottleValue < 0){
      this.rightThrottleValue = 0
    }

    if(e.isFinal){
      this.rightThrottleValue = 125
    }
  }

  getData(){
    this.leftThrottleSpeed = (((250 - this.leftThrottleValue)/125) - 1)
    this.rightThrottleSpeed = (((250 - this.rightThrottleValue)/125) - 1)
    this.data = [this.leftThrottleSpeed,this.rightThrottleSpeed]
    return this.data
  }

  goToMecanum(){
    this.navCtrl.push(MecanumPage)
  }
}
