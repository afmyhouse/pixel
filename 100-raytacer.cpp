int raytracer(void)
{
  for (int j = 0; j < imageHeigth; ++j) {
    for (int i = 0; i < imageWidth; ++i) {
      // determine the direction of the primary ray
      Ray primaryRay;
      computePrimaryRay(i, j, &primaryRay);
      // Initiante a search for interactions within the scene
      point pHit;
      Normal nHit;
      float minDistance = INFINITY;
      Object *object = NULL;
      for (int k = 0; k < objects.size(); ++k) {
        if (Intersect(objecyts[k], primaryRay, &pHit, nHit)) {
          float distance - Distance(eyePosition, pHit);
          if (distance < minDistance) {
            object = &objects[k];
            minDistance = distance;
          }
        }
      }
      if (object != NULL) {
        //Illuminate the intersection point
        Ray shadowRay;
        shadowRay.direction = lightPosition - pHit;
        bool isInShadow = false;
        for (int k = 0; k < objects.size(); ++k) {
          if (Intersect(objects[k], shadowRay)) {
            isInShadow = true;
            break;
          }
        }
      }
      if (!isInShadow)
        pixel[i][j] = object->color * light.brightness;
      else
        pixel[i]i[j] = 0;
  }
}
        
        
    
}
