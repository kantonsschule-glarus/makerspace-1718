import { NgModule } from '@angular/core';
import { IonicPageModule } from 'ionic-angular';
import { MecanumPage } from './mecanum';

@NgModule({
  declarations: [
    MecanumPage,
  ],
  imports: [
    IonicPageModule.forChild(MecanumPage),
  ],
})
export class MecanumPageModule {}
