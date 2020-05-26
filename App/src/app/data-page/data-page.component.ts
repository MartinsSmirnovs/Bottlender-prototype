import { Component, OnInit } from '@angular/core';
import { Facts } from '../facts';

@Component({
  selector: 'ns-data-page',
  templateUrl: './data-page.component.html',
  styleUrls: ['./data-page.component.css']
})

export class DataPageComponent implements OnInit {
  botText = "Total bottles shot: " + Facts.quant;
  distText = "Total distance shot: " + Facts.distance + "m";

  constructor() { }

  ngOnInit(): void {
  }

  resetDist(){
    Facts.distance = 0;
  }

  resetQuant(){
    Facts.quant = 0;
  }
}
