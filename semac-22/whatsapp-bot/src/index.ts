import { WhatsAppProvider } from "./providers/whatsapp.provider";

const sessionName = "woodstock-session";

const whatsAppProvider = new WhatsAppProvider(sessionName);

whatsAppProvider.init();
