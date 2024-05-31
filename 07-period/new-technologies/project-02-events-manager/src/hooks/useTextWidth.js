import { useState } from "react";

export function useTextWidth() {
  const [textWidth, setTextWidth] = useState(0);

  const handleTextLayout = (event) => {
    const { width } = event.nativeEvent.layout;
    setTextWidth(width);
  };

  return { width: textWidth, handleTextLayout };
}
