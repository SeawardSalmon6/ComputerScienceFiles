import { Card } from "@/components/Card";
import styles from "@/components/QRCodeBox/styles";
import { useAuthContext } from "@/contexts/AuthContext/useAuthContext";
import QRCode from "react-native-qrcode-svg";

export function QRCodeBox({ containerStyle }) {
  const { user } = useAuthContext();

  return (
    <Card containerStyle={[styles.container, containerStyle]}>
      <QRCode size={220} value={user?.id || "1"} />
    </Card>
  );
}
